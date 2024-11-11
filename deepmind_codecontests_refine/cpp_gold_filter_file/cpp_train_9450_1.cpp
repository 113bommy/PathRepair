#include<bits/stdc++.h>
#define int long long
using namespace std;
vector<int> s;
int n,k,a[200001],ord[200001];
signed main()
{
	scanf("%lld %lld",&n,&k);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	int cnt=1;
	while(ord[cnt]==0)
	{
		ord[cnt]=s.size();
		s.push_back(cnt);
		cnt=a[cnt];
	}
	int l=ord[cnt];
	int c=s.size()-ord[cnt];
	if(k<l)
		cout<<s[k];
	else
	{
		k-=l;
		k%=c;
		cout<<s[l+k];
	}
	return 0;
}