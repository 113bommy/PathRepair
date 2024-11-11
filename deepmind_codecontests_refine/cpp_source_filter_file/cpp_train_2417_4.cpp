#include <bits/stdc++.h>
using namespace std;
const int SIZEN = 3000;
const double pi = acos(-1);
struct Node {
  int x, y;
  long double arg;
  void getarg() { arg = atan2((1. * y), (1. * x)); }
  bool operator<(const Node &A) const { return arg < A.arg; }
} p[SIZEN], t[SIZEN];
int N;
long long C(int n, int m) {
  if (n < m) return 0;
  if (n < 0 || m < 0) return 0;
  long long ret = 1;
  for (int i = n - m + 1; i <= n; i++) ret = ret * i;
  for (int i = 1; i <= m; i++) ret = ret / i;
  return ret;
}
long long Cross(Node u, Node v) { return 1LL * u.x * v.y - 1LL * u.y * v.x; }
int main() {
  scanf("%d", &N);
  for (int i = 1; i <= N; i++) {
    scanf("%d%d", &p[i].x, &p[i].y);
  }
  long long ans = 0;
  for (int i = 1; i <= N; i++) {
    ans = ans + C(N - 1, 4);
    int cnt = 0;
    for (int j = 1; j <= N; j++)
      if (j != i) {
        t[++cnt].x = p[j].x - p[i].x;
        t[cnt].y = p[j].y - p[i].y;
        t[cnt].getarg();
      }
    sort(t + 1, t + 1 + cnt);
    for (int j = cnt + 1; j <= 2 * cnt; j++) t[j] = t[j - cnt];
    for (int ii = 1, j = 0; ii <= cnt; ii++) {
      j = max(j, ii);
      while (j < 2 * cnt && Cross(t[ii], t[j + 1]) > 0) j++;
      ans = ans - C(j - ii, 3);
    }
  }
  printf("%lld\n", ans);
  return 0;
}
