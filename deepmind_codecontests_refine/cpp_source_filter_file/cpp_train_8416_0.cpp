#include<bits/stdc++.h>
using namespace std;
long long a,b,n,x,ans,t;
int main(){
    cin>>n>>x;
    cin>>a;
    
    for(int i=2;i<=n;i++)
    {
    	cin>>b;
    	if(a+b>x)t=a+b-x,ans+=t,
    	b=b-t,if(b<0)b=0;
    	a=b;
    	
    }
    cout<<ans;

	return 0;
}
