#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAX_N = 110;
int n, a[MAX_N];

void solve()
{
	int tot = 0;
	for(int i=0;i<n;++i) tot+=a[i];
	int ans = 0;
	for(int i=1;i<n;++i)if(abs(n*a[i]-tot)<abs(n*a[ans]-tot))ans=i;
	cout<<ans;
}

int main()
{
	cin >> n;
	for(int i=0;i<n;++i) cin >> a[i];
	solve();
	return 0;
}
