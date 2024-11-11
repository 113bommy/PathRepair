#include<bits\stdc++.h>
using namespace std;

int main()
{
	int n,k;
	cin>>n>>k;
	int a[n+1];
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	int ans=0;
	for(int i=0;i<=n;i++)
	{
		for(int j=0;i+j<=min(n,k);j++)
		{
			vector<int> v;
			int s=0;
			for(int x=1;x<=i;x++){v.push_back(a[x]);s++;}
			for(int x=0;x<j;x++){v.push_back(a[n-x]);s++;}
			sort(v.begin(),v.end());
			int k1=k-s;
			//cout<<k1<<" i "<<i<<" j "<<j<<" sum ";
			while(k1>0 && !v.empty() && *v.begin()<0)
			{
				v.erase(v.begin());
				k1--;
			}
			int sum=0;
			for(int d=0;d<v.size();d++)
			{
				sum+=v[d];
			}
			//cout<<sum<<endl;
			ans=max(ans,sum);	
		}
	}
	cout<<ans;
	return 0;
}