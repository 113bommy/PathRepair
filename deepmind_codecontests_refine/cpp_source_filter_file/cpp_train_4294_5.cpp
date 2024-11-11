#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
const int maxm = 54;
int n, m, k;
long long first[maxm], a[maxm], b[maxm], p[maxm];
long long c[maxm][maxm];
int ipow(long long b, int e) {
  long long ret = 1;
  for (; e; e >>= 1) {
    if (e & 1) ret = ret * b % mod;
    b = b * b % mod;
  }
  return ret;
}
void dfs(int i, long long x) {
  if (i == k)
    p[__builtin_popcountll(x)]++;
  else
    dfs(i + 1, x), dfs(i + 1, x ^ a[i]);
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    long long x;
    cin >> x;
    for (int j = m - 1; j >= 0; j--) {
      if ((x >> j) & 1) {
        if (!first[j]) {
          first[j] = x;
          break;
        }
        x ^= first[j];
      }
    }
  }
  for (int i = 0; i < m; i++) {
    if (first[i]) {
      for (int j = 0; j < i; j++) {
        first[i] ^= ((first[i] >> j) & 1) * first[j];
      }
      for (int j = 0; j < m; j++) {
        if (!first[j]) a[k] = (a[k] << 1) | ((first[i] >> j) & 1);
      }
      a[k] |= 1ll << (m - 1 - k), k++;
    }
  }
  if (k < maxm / 2) {
    dfs(0, 0);
    int x = ipow(2, n - k);
    for (int i = 0; i <= m; i++) {
      cout << (x * p[i] % mod);
      if (i != m) cout << " ";
    }
    cout << '\n';
  } else {
    swap(a, b);
    k = m - k;
    for (int i = 0; i < k; i++) {
      for (int j = 0; j < m - k; j++) {
        a[i] |= ((b[j] >> i) & 1) << j;
      }
      a[i] |= 1ll << (m - 1 - i);
    }
    for (int i = 0; i <= m; i++) {
      c[i][0] = 1;
      for (int j = 1; j <= i; j++) {
        c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % mod;
      }
    }
    dfs(0, 0);
    int x = (long long)ipow((mod + 1) / 2, m - k) * ipow(2, n - m + k) % mod;
    for (int i = 0; i <= m; i++) {
      long long ret = 0;
      for (int j = 0; j <= m; j++) {
        long long cur = 0;
        for (int l = 0; l <= i; l++) {
          (cur += (1 - 2 * (l & 1)) * c[j][l] % mod * c[m - j][i - l] % mod +
                  mod) %= mod;
        }
        (ret += cur * p[j] % mod) %= mod;
      }
      cout << (x * ret % mod);
      if (i != m) cout << " ";
    }
    cout << '\n';
  }
  return 0;
}
