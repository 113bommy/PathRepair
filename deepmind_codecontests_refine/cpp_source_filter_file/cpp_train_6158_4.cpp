#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 5;
int n, m, q, f[N], a[N], L[N], R[N][22], g[N], X[N], Z[N][22], LOG[3000000];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m >> q;
  for (int i = 1, x; i <= n; i++) {
    cin >> x;
    f[x] = i;
  }
  for (int i = 1, x; i <= m; i++) {
    cin >> x;
    a[i] = f[x];
  }
  memset(f, 0, sizeof f);
  fill(f, f + N, m + 1);
  a[m + 1] = n;
  for (int i = m; i > 0; i--) {
    R[i][0] = i;
    if (a[i] != n) {
      R[i][1] = f[a[i] + 1];
    } else
      R[i][1] = i, g[i] = f[1];
    f[a[i]] = i;
  }
  for (int i = 0; i <= 20; i++) R[m + 1][i] = m + 1;
  for (int i = m; i > 0; i--) {
    for (int h = 2; h <= 20; h++) {
      R[i][h] = R[R[i][h - 1]][h - 1];
    }
  }
  for (int i = 1; i <= m; i++) {
    int s = i;
    for (int h = 20; h >= 0; h--)
      if (a[R[s][h]] != n) {
        s = R[s][h];
      }
    if (a[s] != n) {
      s = R[s][1];
    }
    if (a[s] != n || s == m + 1) {
      X[i] = m + 1;
      continue;
    }
    if (a[i] == 1)
      X[i] = s;
    else {
      s = g[s];
      if (s == m + 1) {
        X[i] = m + 1;
        continue;
      }
      for (int h = 20; h >= 0; h--)
        if (s + (1 << h) <= m + 1 && a[R[s][h]] < a[i]) s = R[s][h];
      if (a[s] != a[i] - 1)
        X[i] = m + 1;
      else
        X[i] = s;
    }
  }
  for (int i = 1; i <= m; i++) {
    Z[i][0] = X[i];
  }
  for (int i = 1; i <= 21; i++)
    for (int j = (1 << (i - 1)); j < (1 << i); j++) LOG[j] = i - 1;
  for (int i = m; i > 0; i--) {
    for (int h = 1; h <= 20; h++)
      if (i + (1 << h) <= m + 1)
        Z[i][h] = min(Z[i][h - 1], Z[i + (1 << (h - 1))][h - 1]);
  }
  for (int i = 0, l, r; i < q; i++) {
    cin >> l >> r;
    if (min(Z[l][LOG[r - l + 1]],
            Z[r - (1 << LOG[r - l + 1]) + 1][LOG[r - l + 1]]) <= r)
      cout << 1;
    else
      cout << 0;
  }
  int ptr = 0;
}
