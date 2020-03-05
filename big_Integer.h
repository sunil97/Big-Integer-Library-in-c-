#include <bits/stdc++.h>
    using namespace std;
    #define ll long long
    #define PB push_back
    #define si(n) scanf("%d",&n)
    #define sl(n) scanf("%lld",&n)
    #define pi(n) printf("%d",n)
    #define pl(n) printf("%lld",n)
    string remove(string s)
    {
        int len=s.size();
        int i=0;
        string an="";
        while((s[i]=='+') || (s[i]=='-') || (s[i]=='0'))
        i++;
        while(i<len)
        {
            an=an+s[i];
            i++;
            //cout<<"hgbjh"<<endl;
        }

        //an=s.substr(i,len-i);
        return an;
    }
    string abs(string s){
    	int len=s.size();
    	int i=0;
    	string an="";
    	if(s[i]=='-')
    	i++;
    	while(i<len){
    		an=an+s[i];
    		i++;
		}
		return an;
	}
    string multi(string s11,string s22)
    {
        string s1="";string s2="";

        string ans1="";

        int len1=s11.size(),i,j,tmp;
        int len2=s22.size();
        for(i=len1-1;i>=0;i--)
        {
            s1=s1+s11[i];
        }
        for(i=len2-1;i>=0;i--)
        {
            s2=s2+s22[i];
        }



        int ans[len1+len2];
        for(i=0;i<len1+len2;i++)
        {
            ans[i]=0;
        }
        for(i=0;i<len1;i++)
        {
            for(j=0;j<len2;j++)
            {
                ans[i+j] += (s1[i]-'0')*(s2[j]-'0');
            }
        }
        for(i=0;i<len1+len2;i++)
        {
        tmp = ans[i]/10;
        ans[i] = ans[i]%10;
        ans[i+1] = ans[i+1] + tmp;
        }
        for(i =len1+len2-1; i>= 0;i--)
        {
        if(ans[i] > 0)
            break;
        }
        for(;i >= 0;i--)

       ans1=ans1+(to_string(ans[i]));
       return ans1;
    }
    string add(string s1,string s2)
    {
        int flag=0;
        string ans="";
        string temp="";
        if(s1[0]=='-' || s2[0]=='-')
        {
            ans=ans+'-';
            flag=1;
        }
        int k,i;
        string s11=remove(s1);
        string s22=remove(s2);
        int len11=s11.size();
        int len22=s22.size();
        int mlen=max(len11,len22);
        string a="",b="";
        for(i=len11-1;i>=0;i--)
        {
            a=a+s11[i];
        }
        k=a.size();
        while(k<=mlen)
        {
            a=a+'0';
            k++;
        }
        for(i=len22-1;i>=0;i--)
        {
            b=b+s22[i];
        }
        k=b.size();
        while(k<=mlen)
        {
            b=b+'0';
            k++;
        }
        int temp1,rem,carry=0;
        for(i=0;i<mlen;i++)
        {
            temp1 = (a[i]-'0') + (b[i]-'0') + carry;
        rem = temp1%10;
        carry = temp1/10;
        char re=rem+'0';
        temp=temp+re;

        }
        if(carry!=0)
        {
            char cg=carry+'0';
            temp=temp+cg;
        }

        int templ=temp.size();
        for(i=templ-1;i>=0;i--)
        ans=ans+temp[i];
        return ans;
    }
    string div(string s1, long long divisor){
	          int i,j;
	          int len=s1.size();
	          string ans ="";
	          long long temp;
	            if(s1[0] == '-' && divisor > 0)
        i = 1,j = 0, ans[j++] = '-';
    else if(s1[0] == '-' && divisor < 0)
        i = 1,j = 0, divisor = abs(divisor);
    else if(divisor < 0)
        i = 0, j = 0, ans[j++] = '-', divisor = abs(divisor);
    else
        i = 0, j = 0;
        while(s1[i]){
        temp=temp*10 +	(s1[i]-'0');
        if(temp<divisor){
        	ans[j++]='0';
		}
		 else{
             ans[j++] = (temp / divisor) + '0';
             temp = temp % divisor;
         }
         i++;
		}
		ans[j]='\0';
		return ans;
}

string sub(string s1, string s2){
	  int k,i;
	  	    int asign = s1[0]=='-'?-1:1, bsign = s2[0]=='-'?-1:1;
	  	      if(asign == 1 && bsign == -1){
	  	      	return add(remove(s1),remove(s2));
	  	      }
	  	      if(asign == -1 && bsign == 1){
	  	      	return add(s1,s2);
	  	      }
	  	       if(asign == -1 && bsign == -1){
                return sub(remove(s2), remove(s1));
            }

        string s11=remove(s1);
        string s22=remove(s2);
        int len11=s11.size();
        int len22=s22.size();
        string temp="";
        string ans="";
        int mlen=max(len11,len22);
            string a="",b="";
        for(i=len11-1;i>=0;i--)
        {
            a=a+s11[i];
        }
        k=a.size();
        while(k<=mlen)
        {
            a=a+'0';
            k++;
        }
        for(i=len22-1;i>=0;i--)
        {
            b=b+s22[i];
        }
        k=b.size();
        while(k<=mlen)
        {
            b=b+'0';
            k++;
        }
        int borrow=0;
        for(i=0;i<mlen;i++){
        int 	temp1=(a[i]-'0'-borrow)-(b[i]-'0');
        	if(temp1<0)
        	temp1+=10,borrow=1;
        	else
        	borrow=0;
        	char re=temp1+ '0';
        	temp=temp + re;
		}


		int temp2=temp.size();
        for(i=temp2-1;i>=0;i--)
        ans=ans+temp[i];
        return remove(ans);

}