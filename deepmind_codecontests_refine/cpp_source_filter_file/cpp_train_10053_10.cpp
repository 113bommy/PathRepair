#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-7;
const int maxn = 2e3 + 5;
int n, tA, tB, usedA, usedB;
double A[maxn], B[maxn], tC, l_;
void solve(double exA, double exB) {
  tC = tB = tA = 0;
  double wA, wB, wC;
  for (int i = 1; i <= n; i++) {
    wA = A[i] - exA, wB = B[i] - exB,
    wC = A[i] + B[i] - exA - exB - A[i] * B[i];
    if (wA > 0 && wA >= wB && wA >= wC)
      tA++, tC += wA;
    else if (wB > 0 && wB >= wA && wB >= wC)
      tB++, tC += wB;
    else if (wC > 0 && wC >= wA && wC >= wB)
      tA++, tB++, tC += wC;
  }
}
void check(double exA) {
  double l = 0, r = 1;
  while (r - l > eps) {
    solve(exA, ((l + r) / 2.0));
    if (tB == usedB) break;
    tB < usedB ? r = ((l + r) / 2.0) : l = ((l + r) / 2.0);
  }
  l_ = ((l + r) / 2.0);
}
int main() {
  scanf("%d%d%d", &n, &usedA, &usedB);
  for (int i = 1; i <= n; i++) scanf("%lf", A + i);
  for (int i = 1; i <= n; i++) scanf("%lf", B + i);
  double l = 0, r = 1;
  while (r - l > eps) {
    check(((l + r) / 2.0));
    if (tA == usedA) break;
    tA < usedA ? r = ((l + r) / 2.0) : l = ((l + r) / 2.0);
  }
  printf("%lf", tC + ((l + r) / 2.0) * usedA + l_ * usedB);
  return 0;
}
