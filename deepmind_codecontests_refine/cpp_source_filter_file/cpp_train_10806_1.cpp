#include<iostream>
using namespace std;
int main()
{
	int n,ans=0;
	cin>>n;
	int a[n+1],b[n+1];
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		cin>>b[i];
		if(a[i]>b[i])ans+=a[i]-b[i];
	}
	cout<ans<<endl;
	return 0;
}