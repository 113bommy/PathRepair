#include <bits/stdc++.h>
using namespace std;
const double EPS = 1e-9;
const double PI = acos(-1);
double dgtord(double x) { return (x / 180) * PI; }
int n, m, k, x[1001], y[1001];
struct circle {
  complex<int> c;
  double r;
};
int a, b;
int ans;
circle cr[1001];
int mask[1001][51];
bool ok(int i, int j) {
  long long xxx = x[i] - cr[j].c.real();
  xxx *= xxx;
  long long yyy = y[i] - cr[j].c.imag();
  yyy *= yyy;
  return xxx + yyy < 1LL * cr[j].r * cr[j].r;
}
int cnt(int bin) {
  int ret = 0;
  while (bin) {
    if (bin & 1) {
      ret++;
    }
    bin /= 2;
  }
  return ret;
}
int xx, rr, yy;
int cal[1 << 20];
int main() {
  scanf("%d%d%d", &n, &m, &k);
  int lim = 1 << 20;
  lim--;
  for (int i = 0; i < n; i++) {
    scanf("%d%d", &x[i], &y[i]);
  }
  for (int i = 0; i <= lim; i++) {
    cal[i] = cnt(i);
  }
  for (int i = 0; i < m; i++) {
    scanf("%d%d%d", &rr, &xx, &yy);
    cr[i].r = rr;
    cr[i].c = complex<int>(xx, yy);
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (ok(i, j)) {
        mask[i][j / 20] |= 1 << (j % 20);
      }
    }
  }
  for (int i = 0; i < k; i++) {
    ans = 0;
    scanf("%d%d", &a, &b);
    a--;
    b--;
    for (int j = 0; j < 51; j++) {
      ans += cal[mask[a][j] ^ mask[b][j]];
    }
    printf("%d\n", ans);
  }
  return 0;
}
