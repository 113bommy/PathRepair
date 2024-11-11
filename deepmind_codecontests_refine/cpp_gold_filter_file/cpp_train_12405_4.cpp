#include <bits/stdc++.h>
using namespace std;
const long long mod = 998244353, N = 200010;
long long cnt[N];
long long F[N];
int n;
int main() {
  cin.tie(0);
  cin.sync_with_stdio(0);
  cin >> n;
  F[0] = 1;
  for (int i = 1; i <= n; ++i) F[i] = F[i - 1] * i % mod;
  for (int i = 0; i < 2 * (n - 1); ++i) {
    int u;
    cin >> u;
    ++cnt[--u];
  }
  long long res = n;
  for (int i = 0; i < n; ++i) res = res * F[cnt[i]] % mod;
  cout << res << endl;
}
