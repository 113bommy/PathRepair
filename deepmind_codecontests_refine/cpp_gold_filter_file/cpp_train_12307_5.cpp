#include <bits/stdc++.h>
using namespace std;
const int N = 1005;
struct que {
  double x;
  int v;
  bool operator<(const que &a) const {
    if (abs(x - a.x) > (1e-7)) return x < a.x;
    return v < a.v;
  }
} q[N * 2];
int n, m;
double x[N], y[N], r[N];
int calc(double ang) {
  double X = sin(ang), Y = cos(ang);
  int tot = 0;
  for (int i = (int)(1); i <= (int)(n); i++) {
    double val = -x[i] * X + y[i] * Y;
    q[++tot] = (que){val - r[i], 1};
    q[++tot] = (que){val + r[i], -1};
  }
  sort(q + 1, q + tot + 1);
  int tmp = 0, ans = 0;
  for (int i = (int)(1); i <= (int)(tot); i++) ans = max(ans, tmp += q[i].v);
  return ans;
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = (int)(1); i <= (int)(n); i++)
    scanf("%lf%lf%lf", &x[i], &y[i], &r[i]);
  double st = 0, ed = 2 * acos(-1), step = 0.0005;
  int ans = 0;
  for (; step > (1e-7); step /= 5) {
    int mx = 0;
    double at;
    for (double i = st; i < ed; i += step) {
      int now = calc(i);
      if (now > mx) mx = now, at = i;
    }
    st = at - 5 * step;
    ed = at + 5 * step;
    ans = max(ans, mx);
  }
  printf("%lld\n", 1ll * m * (m + 1) / 2 + n + 1ll * ans * m - m);
}
