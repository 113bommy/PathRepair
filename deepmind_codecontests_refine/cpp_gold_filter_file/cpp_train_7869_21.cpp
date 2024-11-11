#include <bits/stdc++.h>
using namespace std;
using llint = long long;
const int N = 510, B = 1e9 + 7, Z = 5;
int n, m;
int e[N][2 * N];
int x[N];
int ps[N];
char s[N][N];
char bs[N];
int inv[Z];
int rk;
int add(int a, int b) { return (a + b + Z) % Z; }
llint mypw(llint a, int b, int m) {
  llint ret = 1;
  while (b) {
    if (b & 1) ret = ret * a % m;
    a = a * a % m;
    b >>= 1;
  }
  return ret;
}
int solve(int n, int m, int h) {
  int r = 0;
  for (int c = 0, i, j, k; c < h && r < n; ++c) {
    for (i = k = r; i < n; ++i) {
      if (e[i][c] > e[k][c]) k = i;
      if (k != r)
        for (j = c; j < m; ++j) swap(e[k][j], e[r][j]);
      if (e[r][c] == 0) continue;
      for (i = r + 1; i < n; ++i) {
        int t = add(0, Z - e[i][c] * inv[e[r][c]] % Z);
        for (int j = c; j < m; ++j) e[i][j] = add(e[i][j], t * e[r][j] % Z);
      }
      ++r;
    }
  }
  return r;
}
bool check(int x) {
  for (int j = rk; j < m; ++j) {
    if (e[j][x + n] != 0) return 0;
  }
  return 1;
}
void init() {
  for (int i = 1; i < Z; ++i) {
    inv[i] = mypw(i, Z - 2, Z);
  }
}
int main() {
  init();
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; ++i) {
    scanf("%s", s[i]);
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      e[j][i] = s[i][j] - 'a';
    }
  }
  int q;
  scanf("%d", &q);
  for (int i = 0; i < q; ++i) {
    scanf("%s", bs);
    for (int j = 0; j < m; ++j) {
      e[j][i + n] = bs[j] - 'a';
    }
  }
  rk = solve(m, n + q, n);
  int free = n - rk;
  for (int i = 0; i < q; ++i) {
    if (check(i)) {
      printf("%lld\n", mypw(5, free, B));
    } else {
      puts("0");
    }
  }
  return 0;
}
