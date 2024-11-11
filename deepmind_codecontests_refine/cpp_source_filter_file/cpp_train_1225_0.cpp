#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n,k;

	cin>>n>>k;


	int a[n];

	for(i=0;i<n;i++)
		cin>>a[i];

	sort(a,a+n);
	int sum=0;
	for(i=0;i<k;i++)
		sum+=a[i];

	cout<<sum<<"\n";
}
