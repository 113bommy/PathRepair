#include<iostream>
#include<cmath>
using namespace std;
int n,i,e,w,s=1e9,a[1<<19];
char c[1<<19];
int main()
{
	for(cin>>n;i<n;cin>>c[i],a[i]=w,w+=c[i++]==87);
	for(;i>0;s=min(s,a[--i]+e),e+=c[i]==69);
	cout<<s<<endl;
}