#include <bits/stdc++.h>
using namespace std;
const int N = 1005;
int n, m, q, a[N][N], op, x, y, R[N][N], L[N][N], U[N][N], D[N][N];
void update() {
  if (a[x][y]) {
    a[x][y] = 0;
    D[x][y] = U[x][y] = R[x][y] = L[x][y] = 0;
    for (int i = x - 1; i >= 1 && a[i][y]; --i) D[i][y] = x - i;
    for (int i = x + 1; i <= n && a[i][y]; ++i) U[i][y] = i - x;
    for (int j = y - 1; j >= 1 && a[x][j]; --j) R[x][j] = y - j;
    for (int j = y + 1; j <= m && a[x][j]; ++j) L[x][j] = j - y;
  } else {
    a[x][y] = 1;
    D[x][y] = 1 + D[x + 1][y];
    U[x][y] = 1 + U[x - 1][y];
    L[x][y] = 1 + L[x][y - 1];
    R[x][y] = 1 + R[x][y + 1];
    int i, j;
    for (i = x - 1; i >= 1 && a[i][y]; --i) D[i][y] = x - i + D[x][y];
    for (i = x + 1; i <= n && a[i][y]; ++i) U[i][y] = i - x + U[x][y];
    for (j = y - 1; j >= 1 && a[x][j]; --j) R[x][j] = y - j + R[x][y];
    for (j = y + 1; j <= m && a[x][j]; ++j) L[x][j] = j - y + L[x][y];
  }
}
int solve() {
  int ret = 0;
  int u, d, l, r, w;
  u = d = x;
  w = N;
  while (u >= 1 || d <= n) {
    w = min(w, min(R[u][y], R[d][y]));
    for (; u >= 1 && R[u][y] >= w; --u)
      ;
    for (; d <= n && R[d][y] >= w; ++d)
      ;
    ret = max(ret, (d - u - 1) * w);
  }
  u = d = x;
  w = N;
  while (u >= 1 || d <= n) {
    w = min(w, min(L[u][y], L[d][y]));
    for (; u >= 1 && L[u][y] >= w; --u)
      ;
    for (; d <= n && L[d][y] >= w; ++d)
      ;
    ret = max(ret, (d - u - 1) * w);
  }
  l = r = y;
  w = N;
  while (l >= 1 || r <= m) {
    w = min(w, min(D[x][l], D[x][r]));
    for (; l >= 1 && D[x][l] >= w; --l)
      ;
    for (; r <= m && D[x][r] >= w; ++r)
      ;
    ret = max(ret, (r - l - 1) * w);
  }
  l = r = y;
  w = N;
  while (l >= 1 || r <= m) {
    w = min(w, min(U[x][l], U[x][r]));
    for (; l >= 1 && U[x][l] >= w; --l)
      ;
    for (; r <= m && U[x][r] >= w; ++r)
      ;
    ret = max(ret, (r - l - 1) * w);
  }
  return ret;
}
void init() {
  int l, r, u, d;
  for (int i = 1; i <= n; ++i) {
    for (r = 1; r <= m && a[i][r] == 0; ++r) R[i][r] = 0;
    l = r;
    while (l <= m) {
      for (; r <= m && a[i][r]; ++r)
        ;
      for (; l <= r; ++l) R[i][l] = r - l;
      ++r;
    }
    for (l = n; l >= 1 && a[i][l] == 0; --l) L[i][l] = 0;
    r = l;
    while (r >= 1) {
      for (; l >= 1 && a[i][l]; --l)
        ;
      for (; r >= l; --r) L[i][r] = r - l;
      --l;
    }
  }
  for (int j = 1; j <= m; ++j) {
    for (d = 1; d <= n && a[d][j] == 0; ++d) D[d][j] = 0;
    u = d;
    while (u <= n) {
      for (; d <= n && a[d][j]; ++d)
        ;
      for (; u <= d; ++u) D[u][j] = d - u;
      ++d;
    }
    for (u = n; u >= 1 && a[u][j] == 0; --u) U[u][j] = 0;
    d = u;
    while (d >= 1) {
      for (; u >= 1 && a[u][j]; --u)
        ;
      for (; d >= u; --d) U[d][j] = d - u;
      --u;
    }
  }
}
int main() {
  cin >> n >> m >> q;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      scanf("%d", &a[i][j]);
    }
  }
  init();
  while (q--) {
    scanf("%d%d%d", &op, &x, &y);
    if (op == 1)
      update();
    else
      printf("%d\n", solve());
  }
  return 0;
}
