#include <bits/stdc++.h>
using namespace std;
const int N = 5050;
const int mod = 998244353;
int f[2][N], g[N];
int inv[N];
inline int modExp(int a, int n) {
  int b = 1;
  for (; n; n >>= 1) {
    if (n & 1) b = (long long)b * a % mod;
    a = (long long)a * a % mod;
  }
  return b;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  for (int i = 0; i < N; ++i) inv[i] = modExp(i, mod - 2);
  int n;
  cin >> n;
  vector<int> a(n);
  vector<int> cnt(n + 1, 0);
  vector<int> s(n + 1, 0);
  vector<int> o(n + 1, 0);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    ++cnt[a[i]];
  }
  for (int i = 1; i <= n; ++i) {
    s[i] = s[i - 1] + cnt[i];
    o[i] = o[i - 1] + (cnt[i] ? 1 : 0);
  }
  int cur = 0, nxt = 1;
  int ans = 0;
  for (int i = 1; i <= n; ++i) f[nxt][i] = (long long)cnt[i] * inv[n] % mod;
  for (int i = 1; i < n; ++i) {
    swap(cur, nxt);
    for (int i = 0; i <= n; ++i) f[nxt][i] = 0;
    auto update = [&](int x, int v) {
      for (; x < N; x += x & -x) {
        f[nxt][x] = (f[nxt][x] + v) % mod;
      }
    };
    auto get = [&](int x) {
      int res = 0;
      for (; x; x -= x & -x) {
        res = (res + f[nxt][x]) % mod;
      }
      return res;
    };
    for (int j = i; j <= n; ++j) {
      if (o[j] < i || !cnt[j]) continue;
      int lc = n - i;
      ans = ((long long)f[cur][j] * inv[lc] % mod * (cnt[j] - 1) % mod + ans) %
            mod;
      update(j + 1, (long long)f[cur][j] * inv[lc] % mod);
    }
    for (int j = 0; j <= n; ++j) g[j] = (long long)get(j) * cnt[j] % mod;
    for (int j = 0; j <= n; ++j) f[nxt][j] = g[j];
  }
  cout << ans << "\n";
  return 0;
}
