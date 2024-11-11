#include <bits/stdc++.h>
using namespace std;
const int maxn = 510;
int n;
double H, F;
struct Tcxx {
  double l, r;
} A[maxn];
inline int dblc(double x) { return abs(x) < 1e-12 ? 0 : x > 0 ? 1 : -1; }
namespace Ninit {
void init() {
  int i;
  scanf("%d%lf%lf", &n, &H, &F);
  for (i = 0; i < n; ++i) scanf("%lf%lf", &A[i].l, &A[i].r);
}
}  // namespace Ninit
namespace Nsolve {
double ans;
double calc(double A, double B) {
  if (dblc(A) * dblc(B) <= 0) return 0;
  if (dblc(A) < 0) A *= -1, B *= -1;
  double k1 = (H - F) / A, b1 = F;
  double k2 = (F - H) / B, b2 = -F;
  double x = (b2 - b1) / (k1 - k2), y = k1 * x + b1;
  if (dblc(y - H) > 0) return (B * B / (F - H) * (F + H)) * H;
  if (dblc(y + H) < 0) return (A * A / (F - H) * (F + H)) * H;
  return (A + x) * (H - y) / 2 + (B + x) * (y + H) / 2;
}
void solve() {
  int i, j;
  for (i = 0; i < n; ++i) ans += (A[i].r - A[i].l) / (F - H) * 4 * F * H;
  for (i = 0; i < n; ++i)
    for (j = 0; j < n; ++j) {
      ans -= calc(A[i].l, A[j].l) + calc(A[i].r, A[j].r);
      ans += calc(A[i].l, A[j].r) + calc(A[i].r, A[j].l);
    }
  printf("%.7lf\n", ans);
}
}  // namespace Nsolve
int main() {
  Ninit::init();
  Nsolve::solve();
  return 0;
}
