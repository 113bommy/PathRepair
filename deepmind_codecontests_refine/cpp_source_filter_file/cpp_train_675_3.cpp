#include <bits/stdc++.h>
using namespace std;
long long n, a[51][51];
vector<long long> ans;
void solve() {
  cin >> n;
  for (long long i = 1; i <= n; i++) {
    for (long long j = 1; j <= n; j++) cin >> a[i][j];
  }
  for (long long i = 1; i <= n; i++) {
    long long botz = INT_MIN;
    for (long long j = 1; j <= n; j++) {
      botz = max(a[i][j], botz);
    }
    ans.push_back(botz);
  }
  for (long long i = 1; i <= n; i++) {
    for (long long j = 1; j <= n; j++) {
      if (ans[i] == ans[j] && i != j) ans[i]++;
    }
  }
  for (long long i = 0; i < ans.size(); i++) cout << ans[i] << " ";
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solve();
}
