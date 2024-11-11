#include<bits/stdc++.h>
using namespace std;
long long a,b,t,c,ans;
int main (){
    cin>>t;
    for(int i=1;i<=n;i++)
	{
        ans=0;
		cin>>a>>b;
        if(a==b) ans=2*a-2;
        else
		{
            c=sqrt(a*b);
            if(c*c==a*b) c--;
            if(c*(c+1)>=a*b) ans=2*c-2;
            else ans=2*c-1;
        }
        cout<<ans<<endl;
    }
    return 0;
}