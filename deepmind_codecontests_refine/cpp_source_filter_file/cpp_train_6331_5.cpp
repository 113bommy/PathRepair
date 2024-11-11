#include<bits/stdc++.h>
using namespace std;
int n;
int d[15];
int main(void)
{
	cin>>n;
	for(i=0;i<n;i++) cin>>d[i];
	
	int mx =0,s=0;
	for(i=0;i<n;i++) mx=max(mx,d[i]),s+=d[i];
	cout<<s-mx/2<<endl;
	return 0;
}