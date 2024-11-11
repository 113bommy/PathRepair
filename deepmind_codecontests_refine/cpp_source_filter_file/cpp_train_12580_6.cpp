#include<bits/stdc++.h>
using namespace std;
int a[51];
int main()
{
	int n,k;
	cin>>n>>k;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	int sum=0;
	sort(a,a+n);
	for(int i=n-1;i>=n-k;i--)
	{
		sum+=a[i];
	}
	cout>>sum;
	return 0;
}