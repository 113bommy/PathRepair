#include <bits/stdc++.h>
using namespace std;
using ull = uint64_t;
using ll = int64_t;
using ld = long double;
const int MAXN = 1528;
int a[MAXN];
int b[MAXN];
int f[MAXN][MAXN];
int sm[MAXN];
const int INF = 1e9 + 7;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cout.setf(ios::fixed);
  cout.precision(20);
  int n, s, m, k;
  cin >> n >> s >> m >> k;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  for (int i = 0; i < s; ++i) {
    int l, r;
    cin >> l >> r;
    for (int j = l - 1; j < r; ++j) {
      b[j] = max(b[j], r);
    }
  }
  int l = 0, r = INF;
  while (l + 1 < r) {
    int md = (l + r) / 2;
    memset(f, 0, sizeof(f));
    sm[0] = 0;
    for (int i = 0; i < n; ++i) {
      sm[i + 1] = sm[i] + (a[i] <= md);
    }
    for (int i = 0; i <= m; ++i) {
      f[0][i] = 0;
    }
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j <= m; ++j) {
        f[i + 1][j] = max(f[i + 1][j], f[i][j]);
      }
      if (b[i] > i) {
        int ad = sm[b[i]] - sm[i];
        for (int j = 0; j <= m; ++j) {
          int& nf = f[b[i]][j + 1];
          nf = max(nf, f[i][j] + ad);
        }
      }
    }
    if (f[n][m] >= k) {
      r = md;
    } else {
      l = md;
    }
  }
  if (r == INF) {
    cout << -1 << "\n";
  } else {
    cout << r << "\n";
  }
}
