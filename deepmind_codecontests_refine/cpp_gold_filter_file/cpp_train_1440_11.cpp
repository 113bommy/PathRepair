#include<bits/stdc++.h>
using namespace std;
int main()
{
	int a,b,c[110],d=1,f;
	cin>>a>>b;
	for(;d<=a;d++) cin>>c[d];
	for(int e=1;e<=a;e++) b=b-c[e];
	sort(c+1,c+a+1);
	f=b/c[1];
	f=f+a;
	cout<<f;
	return 0;
} 