#include <bits/stdc++.h>
using namespace std;
int Set(int N, int pos) { return N = N | (1 << pos); }
int reset(int N, int pos) { return N = N & ~(1 << pos); }
bool check(int N, int pos) { return (bool)(N & (1 << pos)); }
int cas = 1;
int dxx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dyy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
int dx[] = {-1, 0, 0, 1};
int dy[] = {0, -1, 1, 0};
int c[5006], x[5006], y[5006], v[5006];
int main() {
  int n, m, i, j, k, l, ai[5005];
  for (i = 1; i <= 5005; i++) ai[i] = 1000000000;
  scanf("%d %d", &n, &m);
  int ck;
  ck = 1;
  int ij = 0;
  for (int i = 1; i <= m; i++) scanf("%d %d %d %d", &c[i], &x[i], &y[i], &v[i]);
  ;
  l = m;
  while (m > 0) {
    if (c[m] == 1) {
      for (i = x[m]; i <= y[m]; i++) {
        if (ai[i] != 1000000000) {
          ai[i] -= v[m];
        }
      }
    } else {
      for (i = x[m]; i <= y[m]; i++) {
        if (ai[i] >= v[m]) {
          ai[i] = v[m];
        }
      }
    }
    m--;
  }
  int ans[5006];
  for (i = 1; i <= n; i++) {
    ans[i] = ai[i];
  }
  for (j = 1; j <= l; j++) {
    if (c[j] == 1) {
      for (i = x[j]; i <= y[j]; i++) {
        if (ai[i] != 1000000000) {
          ai[i] += v[j];
        }
      }
    } else {
      ck = 0;
      for (i = x[j]; i <= y[j]; i++) {
        if (ai[i] >= v[j]) {
          ck = 1;
        }
      }
      if (ck == 0) break;
    }
  }
  if (ck == 0)
    printf("NO\n");
  else {
    printf("YES\n", n);
    for (i = 1; i <= n; i++) printf("%d ", ans[i]);
  }
}
