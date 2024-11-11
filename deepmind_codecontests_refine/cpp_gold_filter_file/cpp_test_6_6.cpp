#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
const int N = 1e5 + 5;
int n, a[N], phi[N], cnt[N];
vector<int> f[N];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  for (int i = 1; i <= N; ++i)
    for (int j = 1; j <= N / i; ++j) f[i * j].push_back(i);
  for (int i = 1; i <= N; ++i) {
    phi[i] = i;
    for (auto u : f[i])
      if (u != i) phi[i] -= phi[u];
  }
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  long long ans = 0;
  memset(cnt, 0, sizeof(cnt));
  for (int x = 1; x <= n; ++x) {
    vector<int> res;
    for (int i = 1; i <= n / x; ++i) {
      for (auto y : f[a[i * x]]) {
        if (cnt[y] == 0) res.push_back(y);
        cnt[y]++;
      }
    }
    for (auto y : res) {
      ans =
          (ans + ((1LL * phi[x] * phi[y]) % MOD * cnt[y]) % MOD * cnt[y]) % MOD;
      cnt[y] = 0;
    }
  }
  cout << ans;
}
