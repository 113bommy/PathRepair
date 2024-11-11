#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f2f1f0f;
const long long LINF = 1ll * INF * INF;
const int MAX_N = 1e5 + 100, MAX_NR = 1e6 + 100;
const double EPS = 1e-9;
int N, S;
vector<pair<int, int> > Nr[2];
pair<double, double> merge(pair<double, double> a, pair<double, double> b) {
  return pair<double, double>(max(a.first, b.first), min(a.second, b.second));
}
int Sum[2][MAX_NR];
void getP(int k, double t) {
  double s = S;
  for (pair<int, int> &e : Nr[k]) {
    int xx, vv;
    tie(xx, vv) = e;
    double x = xx, v = vv;
    pair<double, double> now = pair<double, double>(-INF, +INF);
    if (x / v > t) {
      double minV = (x / (v + s));
      if (t < minV)
        now = pair<double, double>(INF, -INF);
      else
        now = pair<double, double>(x, (t * (s * s - v * v) + x * v) / s);
    }
    int l = max(1ll, (long long)(now.first - EPS));
    int r = min(999999ll, (long long)(now.second + EPS));
    if (k == 1) l = 1000000 - l, r = 1000000 - r, swap(l, r);
    if (l <= r) Sum[k][l]++, Sum[k][r + 1]--;
  }
}
bool isWell(double t) {
  for (int i = 1; i < MAX_NR; i++) Sum[0][i] = Sum[1][i] = 0;
  getP(0, t);
  getP(1, t);
  for (int i = 1; i < MAX_NR; i++) {
    Sum[0][i] += Sum[0][i - 1];
    Sum[1][i] += Sum[1][i - 1];
    if (Sum[0][i] > 0 && Sum[1][i] > 0) return true;
  }
  return false;
}
int main() {
  cin >> N >> S;
  vector<int> co;
  for (int i = 0; i < N; i++) {
    int x, v, d;
    scanf("%d%d%d", &x, &v, &d);
    d--;
    if (d == 1) x = 1000000 - x;
    Nr[d].push_back(pair<int, int>(x, v));
  }
  double ans = -1;
  int cnt = 0;
  for (double l = 0, r = 1e6; l <= r && cnt < 100; cnt++) {
    double m = (l + r) / 2;
    if (isWell(m))
      ans = r = m;
    else
      l = m;
  }
  printf("%.20f\n", ans);
  return 0;
}
