#include <bits/stdc++.h>

using namespace std;

int n,k;
vector<int> a;

bool ok(int p) {
	if(a[p]>=k) return true;
	vector<vector<char> > dp(n+1,vector<char>(k));
	dp[0][0]=true;
	for(int i=0;i<n;++i) {
		for(int j=0;j<k;++j) {
			dp[i+1][j]|=dp[i][j];
			if(i==p||j+a[i]>=k) continue;
			dp[i+1][j+a[i]]|=dp[i][j];
			if(j+a[i]>=k-a[p]&&dp[i+1][j+a[i]]) return true;
		}
	}
	return false;
}

int main() {
	cin >> n >> k;
	a.resize(n);
	for(auto&e:a) cin >> e;
	sort(a.begin(),a.end());
	int l=-1,r=n;
	while(r-l>1) {
		int mid=(l+r)/2;
		if(ok(mid)) r=mid;
		else l=mid;
	}
	cout << r << endl;
	
	return 0;
}