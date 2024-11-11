#include <bits/stdc++.h>
using namespace std;
const int maxn = 2010, P = 1e6 + 3, mod = 1e9 + 7;
int n, m, pw[maxn];
struct Hash {
  vector<int> v, rv;
  int N;
  void in() {
    string s;
    cin >> s;
    N = int((s).size());
    int num = 0;
    for (int i = 0; i < N; i++) {
      num = (1ll * num * P + s[i]) % mod;
      v.push_back(num);
    }
    num = 0;
    for (int i = N - 1; i >= 0; i--) {
      num = (1ll * num * P + s[i]) % mod;
      rv.push_back(num);
    }
  }
  int ask(int _rv, int l, int r) {
    --l, --r;
    int x;
    if (_rv) {
      r = N - 1 - r, l = N - 1 - l;
      swap(l, r);
      x = rv[r];
      if (l != 0) x = (1ll * x - 1ll * pw[r - l + 1] * rv[l - 1]) % mod;
    } else {
      x = v[r];
      if (l != 0) x = (1ll * x - 1ll * pw[r - l + 1] * v[l - 1]) % mod;
    }
    if (x < 0) x += mod;
    return x;
  }
};
Hash h[2], s;
int suf[maxn][maxn][2], pre[maxn][maxn][2];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  pw[0] = 1;
  for (int i = 1; i < maxn; i++) pw[i] = 1ll * P * pw[i - 1] % mod;
  h[0].in(), h[1].in(), s.in();
  n = h[0].N, m = s.N;
  for (int j = 1; j <= n; j++) {
    for (int k = 0; k < 2; k++) {
      pre[1][j][k] = suf[1][j][k] = h[k].ask(0, j, j) == s.ask(0, 1, 1);
    }
  }
  for (int i = 2; i <= m; i++) {
    for (int j = 1; j <= n; j++) {
      for (int k = 0; k < 2; k++) {
        if (h[k].ask(0, j, j) == s.ask(0, i, i)) {
          if (h[1 - k].ask(0, j, j) == s.ask(0, i - 1, i - 1))
            pre[i][j][k] = pre[i - 2][j - 1][1 - k];
          pre[i][j][k] = (pre[i][j][k] + pre[i - 1][j - 1][k]) % mod;
          int I = i / 2;
          if (2 * I == i && 1 <= j - I + 1 &&
              h[k].ask(0, j - I + 1, j) == s.ask(0, i - I + 1, i) &&
              h[1 - k].ask(0, j - I + 1, j) == s.ask(1, i - I - I + 1, i - I))
            pre[i][j][k] = (pre[i][j][k] + 1) % mod;
        }
      }
    }
  }
  for (int i = 2; i <= m; i++) {
    for (int j = n; j >= 1; j--) {
      for (int k = 0; k < 2; k++) {
        if (h[k].ask(0, j, j) == s.ask(0, i, i)) {
          if (h[1 - k].ask(0, j, j) == s.ask(0, i - 1, i - 1))
            suf[i][j][k] = suf[i - 2][j + 1][1 - k];
          suf[i][j][k] = (suf[i][j][k] + suf[i - 1][j + 1][k]) % mod;
          int I = i / 2;
          if (2 * I == i && j + I - 1 <= n &&
              h[k].ask(0, j, j + I - 1) == s.ask(1, i - I + 1, i) &&
              h[1 - k].ask(0, j, j + I - 1) == s.ask(0, i - I - I + 1, i - I))
            suf[i][j][k] = (suf[i][j][k] + 1) % mod;
        }
      }
    }
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < 2; j++) {
      ans = (ans + suf[m][i][j]) % mod;
      ans = (ans + pre[m][i][j]) % mod;
    }
  }
  if (m == 1) {
    for (int i = 1; i <= n; i++) {
      for (int j = 0; j < 2; j++) {
        ans -= h[j].ask(0, i, i) == s.ask(0, m, m);
      }
    }
  }
  if (m == 2) {
    for (int i = 1; i <= n; i++) {
      for (int j = 0; j < 2; j++) {
        ans -= (h[j].ask(0, i, i) == s.ask(0, m, m)) &&
               (h[1 - j].ask(0, i, i) == s.ask(0, m - 1, m - 1));
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < 2; j++) {
      for (int k = 2; 2 * k < m; k++) {
        if (i + k - 1 <= n &&
            h[j].ask(0, i, i + k - 1) == s.ask(1, m - k + 1, m) &&
            h[1 - j].ask(0, i, i + k - 1) == s.ask(0, m - k - k + 1, m - k))
          ans = (ans + pre[m - 2 * k][i - 1][1 - j]) % mod;
        if (i - k + 1 >= 1 &&
            h[j].ask(0, i - k + 1, i) == s.ask(0, m - k + 1, m) &&
            h[1 - j].ask(0, i - k + 1, i) == s.ask(1, m - k - k + 1, m - k))
          ans = (ans + suf[m - 2 * k][i + 1][1 - j]) % mod;
      }
    }
  }
  ans %= mod;
  if (ans < 0) ans += mod;
  return cout << ans << endl, 0;
}
