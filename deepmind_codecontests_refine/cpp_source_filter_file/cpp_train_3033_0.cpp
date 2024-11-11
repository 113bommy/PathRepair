#include <bits/stdc++.h>
using namespace std;
const int M = 1e6 + 10;
int b[M][33];
int p[M][33];
int T, n, m;
void init() {
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= 30; j++) {
      b[i][j] = 0;
      p[i][j] = 0;
    }
  }
}
void add(int x, int t) {
  for (int i = 30; i >= 0; i--) {
    b[t][i] = b[t - 1][i];
    p[t][i] = p[t - 1][i];
  }
  int ct = t;
  for (int i = 30; i >= 0; i--) {
    if (x & (1 << i)) {
      if (b[t][i]) {
        if (p[t][i] < t) {
          swap(b[t][i], x);
          swap(p[t][i], ct);
        }
        x ^= b[t][i];
      } else {
        b[t][i] = x;
        p[t][i] = ct;
        break;
      }
    }
  }
}
int Max(int l, int r) {
  int res = 0;
  for (int i = 30; i >= 0; i--) {
    if (p[r][i] < l) continue;
    if ((b[r][i] ^ res) > res) res ^= b[r][i];
  }
  return res;
}
int main() {
  scanf("%d", &n);
  int a;
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a);
    add(a, i);
  }
  scanf("%d", &m);
  for (int i = 1; i <= m; i++) {
    int r, l;
    scanf("%d%d", &l, &r);
    printf("%d\n", Max(l, r));
  }
}
