#include <bits/stdc++.h>
using namespace std;
int m;
string st;
const int MOD = 1e9 + 7;
const int N = 100010;
int fac[N], inv[N], ai[N], bi[N];
int ans[N], sum[N], cnt;
int _1[N], _2[N], _3[N];
vector<int> vi[N];
int C(int a, int b) { return 1ll * fac[a] * inv[b] % MOD * inv[a - b] % MOD; }
int powi(int a, int b) {
  int c = 1;
  for (; b; b >>= 1, a = 1ll * a * a % MOD)
    if (b & 1) c = 1ll * c * a % MOD;
  return c;
}
int main() {
  fac[0] = 1;
  for (int i = 1; i < N; ++i) fac[i] = 1ll * fac[i - 1] * i % MOD;
  inv[N - 1] = powi(fac[N - 1], MOD - 2);
  for (int i = N - 2; ~i; --i) inv[i] = 1ll * inv[i + 1] * (i + 1) % MOD;
  ios ::sync_with_stdio(0);
  cin >> m >> st;
  int l = st.length();
  for (int i = 1; i <= m; ++i) {
    int opt;
    cin >> opt;
    if (opt == 1) {
      cin >> st;
      l = st.length();
    } else {
      cnt++;
      vi[l].push_back(l);
      cin >> bi[cnt];
    }
  }
  _1[0] = 1;
  _2[0] = 1;
  _3[0] = 1;
  int tmp = powi(26, MOD - 2);
  for (int j = 1; j < N; ++j)
    _1[j] = 1ll * _1[j - 1] * (26 - 1) % MOD,
    _2[j] = 1ll * _2[j - 1] * 26 % MOD, _3[j] = 1ll * _3[j - 1] * tmp % MOD;
  for (int i = 1; i < N; ++i)
    if (vi[i].size()) {
      for (int j = 0; j < i; ++j) sum[j] = 0;
      for (int j = i; j < N; ++j)
        sum[j] =
            (sum[j - 1] + 1ll * C(j - 1, i - 1) * _1[j - i] % MOD * _3[j]) %
            MOD;
      for (int j = i; j < N; ++j) sum[j] = 1ll * sum[j] * _2[j] % MOD;
      for (int j = 0; j < vi[i].size(); ++j) ans[vi[i][j]] = sum[bi[vi[i][j]]];
    }
  for (int i = 1; i <= cnt; ++i) cout << ans[i] << endl;
}
