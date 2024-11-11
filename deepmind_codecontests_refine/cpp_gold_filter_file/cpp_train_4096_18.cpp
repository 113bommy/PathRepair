#include <bits/stdc++.h>
using namespace std;
inline long long pow(long long a, int b) {
  long long tmp = 1;
  for (; b; b >>= 1) {
    if (b & 1) tmp = (long long)tmp * a % 1000000007;
    a = (long long)a * a % 1000000007;
  }
  return tmp;
}
template <class T>
inline void R(T &xx) {
  xx = 0;
  char ch = getchar();
  bool F = 0;
  while ((ch < '0' || ch > '9') && ch != '-') ch = getchar();
  if (ch == '-') F = 1, ch = getchar();
  while (ch >= '0' && ch <= '9') xx = xx * 10 + ch - 48, ch = getchar();
  if (F) xx = -xx;
}
double ans, rf, re, rs;
int n, nf, ne, ns, df, de, pos[777];
bool v[777];
inline double cross(double a, double b, double c, double d) {
  return max(0., min(b, d) - max(a, c));
}
void work() {
  double tp = 2. * nf * rf * df + 2. * ne * re * de;
  vector<double> a;
  for (int i = (1); i <= (n); i++)
    if (!v[i]) {
      double tf = 0, te = 0;
      for (int j = (1); j <= (ns); j++) {
        tf += df * cross((i + 1) / 2 - rf, (i + 1) / 2 + rf, pos[j] - rs,
                         pos[j] + rs);
        te += de * cross((i + 1) / 2 - re, (i + 1) / 2 + re, pos[j] - rs,
                         pos[j] + rs);
      }
      tp += tf;
      a.push_back(tf - te);
    }
  sort(a.begin(), a.end());
  for (int i = 0; i < (int)(ne); i++) tp -= a[i];
  ans = max(ans, tp);
}
void dfs(int x, int y) {
  if (y > n - x + 1) return;
  if (x > n) {
    work();
    return;
  }
  v[x] = 0;
  dfs(x + 1, y);
  if (y) v[x] = 1, pos[y] = x + 1 >> 1, dfs(x + 1, y - 1);
}
int main() {
  R(nf), R(ne), R(ns), R(rf), R(re), R(rs), R(df), R(de);
  n = ne + ns + nf;
  rf = sqrt(rf * rf - 1), re = sqrt(re * re - 1), rs = sqrt(rs * rs - 1);
  dfs(1, ns);
  printf("%.10f\n", ans);
  return 0;
}
