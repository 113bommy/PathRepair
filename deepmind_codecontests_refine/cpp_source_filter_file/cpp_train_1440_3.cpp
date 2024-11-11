#include<iostream>
#include<algoprithm>
using namespace std;
int main()
{
	int n,x;cin>>n>>x;
	int a[108]={0};
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		x-=a[i];
	}
	int ans=n;
	sort(a,a+n);
	cout<<ans+x/a[0]<<endl;
	return 0;
}