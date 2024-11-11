#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
const int N = 1e5 + 4;
long long powmod(long long a, long long b, long long mod) {
  long long res = 1;
  a %= mod;
  for (; b; b >>= 1) {
    if (b & 1) res = (res * a) % mod;
    a = (a * a) % mod;
  }
  return res;
}
int main() {
  int n;
  cin >> n;
  int a[n];
  int ans[n];
  for (long long i = 0; i < n; i++) cin >> a[i];
  vector<int> g[N];
  int ma = 0;
  for (long long i = 0; i < n; i++) g[a[i]].push_back(i + 1);
  for (int i = 2; i < N; i++) {
    if (g[i].size() > g[i - 1].size()) {
      return cout << -1, 0;
    }
  }
  for (int i = 1; i <= n; i++) {
    int cnt = 1;
    for (int node : g[i]) ans[node - 1] = cnt, cnt++;
    ma = max(ma, cnt - 1);
  }
  cout << ma << "\n";
  for (int i = 0; i < n; i++) cout << ans[i] << " ";
  return 0;
}
