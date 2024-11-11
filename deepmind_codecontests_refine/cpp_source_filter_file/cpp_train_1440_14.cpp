#include<bits/stdc++.h>
using namespace std;
int a[520],n,x;
int main()
{
	cin>>n>>x;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]; x-=a[i];
	}
	sort(a+1,a+n+1);
	cout<<n+x/a[i];
	return 0; 
} 