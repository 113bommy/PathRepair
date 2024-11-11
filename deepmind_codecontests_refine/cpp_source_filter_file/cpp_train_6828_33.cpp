#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
const int N = 123456;
int a[N];
int dp[N][350];
int n;
int go(int p, int k) {
  if (p > n) return 0;
  int &ret = dp[p][k];
  if (ret != -1) return ret;
  ret = 1 + go(p + a[p] + k, k);
  return ret;
}
int brute(int p, int k) {
  if (p > n) return 0;
  return 1 + brute(p + a[p] + k, k);
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  memset(dp, -1, sizeof(dp));
  int q;
  cin >> q;
  for (int i = 0; i < q; i++) {
    int p, k;
    cin >> p >> k;
    if (k * k < n)
      cout << go(p, k) << "\n";
    else
      cout << brute(p, k) << "\n";
  }
  return 0;
}
