#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int x = 0, f = 1, c;
  while (c = getchar(), c < '0' || c > '9')
    if (c == '-') f = -1;
  for (; c >= '0' && c <= '9'; c = getchar()) x = x * 10 + c - '0';
  return x * f;
}
const int MAXN = 100005;
const double pi = acos(-1.0);
int n, u[MAXN];
double v[MAXN];
pair<double, int> rr[MAXN];
void input() {
  n = read();
  for (int i = 1; i <= n; ++i) {
    int r = read();
    int h = read();
    v[i] = pi * r * r * h;
    rr[i] = make_pair(v[i], i);
  }
  sort(rr + 1, rr + n + 1);
  int tot = 1;
  for (int i = 1; i <= n; ++i) {
    u[rr[i].second] = tot;
    tot += fabs(rr[i].first - rr[i + 1].first) >= 1e-8;
  }
}
double c[MAXN];
double query(int pos) {
  double res = 0;
  for (int i = pos; i; i -= i & -i) res = max(res, c[i]);
  return res;
}
void update(int pos, double val) {
  for (int i = pos; i <= n; i += i & -i) c[i] = max(c[i], val);
}
void solve() {
  double ans = 0;
  for (int i = 1; i <= n; ++i) {
    double s = query(u[i]);
    ans = max(ans, s + v[i]);
    update(u[i], s + v[i]);
  }
  printf("%.9f\n", ans);
}
int main() {
  input();
  solve();
  return 0;
}
