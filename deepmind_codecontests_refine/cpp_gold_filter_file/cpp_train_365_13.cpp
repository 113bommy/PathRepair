#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-10;
pair<double, double> operator+(pair<double, double> first,
                               pair<double, double> second) {
  return make_pair(first.first + second.first, first.second + second.second);
}
pair<double, double> operator-(pair<double, double> first,
                               pair<double, double> second) {
  return make_pair(first.first - second.first, first.second - second.second);
}
pair<double, double> operator*(pair<double, double> first, double second) {
  return make_pair(first.first * second, first.second * second);
}
pair<double, double> operator/(pair<double, double> first, double second) {
  return make_pair(first.first / second, first.second / second);
}
double Cross(pair<double, double> first, pair<double, double> second) {
  return first.first * second.second - first.second * second.first;
}
double Dot(pair<double, double> first, pair<double, double> second) {
  return first.first * second.first + first.second * second.second;
}
double Dis(pair<double, double> first, pair<double, double> second) {
  return Dot(first - second, first - second);
}
pair<double, double> d[1001];
int n;
pair<double, double> getinter(
    const pair<pair<double, double>, pair<double, double> > &a,
    const pair<pair<double, double>, pair<double, double> > &b) {
  pair<double, double> u = a.first - b.first;
  double t = Cross(b.second, u) / Cross(a.second, b.second);
  return a.first + a.second * t;
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%lf%lf", &d[i].first, &d[i].second);
  pair<double, double> L = d[1], R = d[2];
  pair<pair<double, double>, pair<double, double> > L1 = make_pair(L, R - L);
  for (int i = 3; i < n; i++)
    for (int j = i + 1; j <= n; j++) {
      pair<pair<double, double>, pair<double, double> > L2 =
          make_pair(d[i], d[j] - d[i]);
      if (fabs(Cross(L1.second, L2.second)) < eps) {
        if (Dot(L1.second, L2.second) > 0) {
          printf("0\n");
          return 0;
        }
        continue;
      }
      pair<double, double> J = getinter(L1, L2);
      if (Dot(J - d[i], L2.second) < 0)
        R = Dot(L - R, J - R) < eps ? R : J;
      else
        L = Dot(R - L, J - L) < eps ? L : J;
      if (Dot(R - L, L1.second) < 0) {
        printf("0\n");
        return 0;
      }
    }
  if (abs(L.first - R.first) < eps && abs(L.second - R.second) < eps) {
    printf("1\n");
    return 0;
  }
  int ans = 0;
  pair<double, double> Now = d[1], Vec;
  if (L1.second.first == 0)
    Vec = make_pair(1, 0);
  else
    Vec = L1.second / fabs(L1.second.first);
  for (; Dot(Now - L, R - L) < 0; Now = Now + Vec)
    ;
  for (; Dot(L - Now, R - Now) - eps < 0; Now = Now + Vec)
    if (fabs(Now.second - round(Now.second)) < eps) ans++;
  printf("%d\n", ans);
  return 0;
}
