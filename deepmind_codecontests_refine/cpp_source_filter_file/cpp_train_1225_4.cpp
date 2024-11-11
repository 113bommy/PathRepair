#include<bits/stdc++.h>
using namespace std;
int a,b,c=0,i,p[1010];
int main()
{
	cin>>a>>b;
	for(i=0;i<a;++i)cin>>p[i];
	sort(p,p+a);
	for(i=0;i<b;++i)ans+=p[i];
	cout<<c;
}
