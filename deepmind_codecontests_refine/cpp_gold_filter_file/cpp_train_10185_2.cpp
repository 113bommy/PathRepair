#include<bits/stdc++.h>
using namespace std;
int a,b,c,n,ans;
int main()
{
    cin>>a>>b>>c>>n;
    for(int i=0;i<=a;i++)
		for(int j=0;j<=b;j++)
	      	if(n-i*500-j*100>=0 && n-i*500-j*100<=c*50) ans++;
    cout<<ans;
    return 0;
}