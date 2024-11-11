#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
template <typename X>
inline bool minimize(X& p, X q) {
  if (p <= q) return 0;
  p = q;
  return 1;
}
template <typename X>
inline bool maximize(X& p, X q) {
  if (p >= q) return 0;
  p = q;
  return 1;
}
const int MAXN = 100005;
double Ya[MAXN], Yb[MAXN], L[MAXN];
double dis(double dx, double dy) { return sqrt(dx * dx + dy * dy); }
int main() {
  int N, M;
  double a, b;
  scanf("%d%d%lf%lf", &N, &M, &a, &b);
  for (int i = 1; i <= N; ++i) scanf("%lf", Ya + i);
  for (int i = 1; i <= M; ++i) scanf("%lf", Yb + i);
  for (int i = 1; i <= M; ++i) scanf("%lf", L + i);
  double ans = 1e100;
  int ap = 1, bp = 1;
  for (int i = 1, j = 1; i <= M; ++i) {
    double temp = a * Yb[i] / b;
    while (j < N && Ya[j] < temp) ++j;
    if (minimize(ans, dis(a, Ya[j]) + dis(b - a, Yb[i] - Ya[j]) + L[i]))
      ap = j, bp = i;
    if (Ya[j] > temp && j != 1 &&
        minimize(ans, dis(a, Ya[j - 1]) + dis(b - a, Yb[i] - Ya[j - 1]) + L[i]))
      ap = j - 1, bp = i;
  }
  printf("%d %d\n", ap, bp);
  return 0;
}
