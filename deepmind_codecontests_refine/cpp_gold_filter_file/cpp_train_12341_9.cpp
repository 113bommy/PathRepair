#include <bits/stdc++.h>
using namespace std;
const long long INF = 8 * 1e18;
const int MAXN = 1e5;
int n;
long long x[MAXN][3];
long long y[3];
inline long long llmax(long long a, long long b) { return (a < b ? b : a); }
inline long long llmin(long long a, long long b) { return (a > b ? b : a); }
bool ok(long long k) {
  long long lwb[4], upb[4];
  for (int j = 0; j < 4; j++) {
    lwb[j] = -INF;
    upb[j] = INF;
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 4; j++) {
      long long dk = 0;
      for (int h = 0; h < 3; h++) {
        dk += (h == j ? -1 : 1) * x[i][h];
      }
      lwb[j] = llmax(lwb[j], -k + dk);
      upb[j] = llmin(upb[j], k + dk);
    }
  }
  for (int j = 0; j < 4; j++) {
    if (lwb[j] > upb[j]) return 0;
  }
  long long s[4];
  for (int m2 = 0; m2 <= 1; m2++) {
    s[3] = 0;
    for (int j = 0; j < 3; j++) {
      s[j] = lwb[j] + (abs(lwb[j] % 2) != m2);
      s[3] += s[j];
    }
    if (s[3] < lwb[3]) {
      long long to_add = lwb[3] + (abs(lwb[3] % 2) != m2) - s[3];
      for (int j = 0; j < 3; j++) {
        long long dd = llmin(to_add, (upb[j] - s[j]) / 2 * 2);
        s[j] += dd;
        s[3] += dd;
        to_add -= dd;
      }
    }
    bool ok = 1;
    for (int j = 0; j < 4; j++) {
      if (s[j] < lwb[j] || s[j] > upb[j]) ok = 0;
    }
    if (!ok) continue;
    for (int h = 0; h < 3; h++) {
      y[h] = 0;
      for (int j = 0; j < 3; j++) y[h] += (j == h ? 0 : 1) * s[j];
      y[h] /= 2;
    }
    return 1;
  }
  return 0;
}
void solve() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < 3; j++) scanf("%I64d", &x[i][j]);
  long long L = -1, R = INF / 2;
  while (R - L > 1) {
    long long M = (R + L) / 2;
    if (ok(M))
      R = M;
    else
      L = M;
  }
  for (int j = 0; j < 3; j++)
    printf(
        "%I64d"
        " ",
        y[j]);
  printf("\n");
}
int main() {
  int _;
  scanf("%d", &_);
  while (_--) {
    solve();
  }
  return 0;
}
