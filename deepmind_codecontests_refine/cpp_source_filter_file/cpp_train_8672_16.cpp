#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000000;
double x[maxn], a[maxn];
double sum[maxn];
pair<pair<double, double>, double> Mx[maxn];
void build(int Now, int L, int R) {
  if (L == R) {
    sum[Now] = a[L];
    Mx[Now].first.first = Mx[Now].first.second = a[L];
    Mx[Now].second = max(a[L], 0.0);
    return;
  }
  int Mid = (L + R) >> 1;
  build(Now << 1, L, Mid);
  build(Now << 1 | 1, Mid + 1, R);
  sum[Now] = sum[Now << 1] + sum[Now << 1 | 1];
  Mx[Now].first.first = max(Mx[Now << 1].first.first,
                            sum[Now << 1] + Mx[Now << 1 | 1].first.first);
  Mx[Now].first.second = max(Mx[Now << 1 | 1].first.second,
                             sum[Now << 1 | 1] + Mx[Now << 1].first.second);
  Mx[Now].second =
      max(max(Mx[Now << 1].second, Mx[Now << 1 | 1].second),
          Mx[Now << 1].first.second + Mx[Now << 1 | 1].first.first);
}
pair<pair<double, double>, double> query(int Now, int L, int R, int l, int r) {
  if (l <= L && r >= R) return Mx[Now];
  int Mid = (L + R) / 2;
  if (r <= Mid) return query(Now << 1, L, Mid, l, r);
  if (l > Mid)
    return query(Now << 1 | 1, Mid + 1, R, l, r);
  else {
    pair<pair<double, double>, double> res, tmp;
    res = query(Now << 1, L, Mid, l, r);
    tmp = query(Now << 1 | 1, Mid + 1, R, l, r);
    res.second =
        max(max(res.second, tmp.second), res.first.second + tmp.first.first);
    res.first.first = max(res.first.first, sum[Now << 1] + tmp.first.first);
    res.first.second =
        max(tmp.first.second, sum[Now << 1 | 1] + res.first.second);
    return res;
  }
}
int main() {
  int N, M, i;
  double C, P, ans;
  scanf("%d%d%lf", &N, &M, &C);
  for (i = 1; i <= N; i++) scanf("%lf", &x[i]);
  for (i = 1; i < N; i++) {
    scanf("%lf", &P);
    a[i] = (x[i + 1] - x[i]) / 2 - C * P / 100.0;
  }
  build(1, 1, N - 1);
  for (i = 1; i <= M; i++) {
    int L, R;
    scanf("%d%d", &L, &R);
    ans += query(1, 1, N - 1, L, R - 1).second;
  }
  printf("%.6lf\n", ans);
  return 0;
}
