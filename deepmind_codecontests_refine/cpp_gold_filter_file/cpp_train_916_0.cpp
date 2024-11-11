#include <bits/stdc++.h>
using namespace std;
long long n,m,i,j,sum,ans;
map<long long,long long> cnt;
int main()
{
	cnt[0]=1;
	ios_base::sync_with_stdio(0);
	cin>>n;
	for (i=1;i<=n;i++)
	{
		long long x;
		cin>>x;
		sum+=x;
		ans+=cnt[sum];
		cnt[sum]++;
	}
	cout<<ans;
	return 0;
}