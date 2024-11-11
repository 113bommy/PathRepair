#include <bits/stdc++.h>
using namespace std;
double v[302000], b[302000];
struct node {
  int L, R;
  double Max;
  int Mid() { return (L + R) / 2; }
} a[302000 * 4];
void Build(int r, int L, int R) {
  a[r].L = L, a[r].R = R;
  a[r].Max = 0;
  if (L == R) return;
  Build(r << 1, L, a[r].Mid());
  Build(r << 1 | 1, a[r].Mid() + 1, R);
}
double Query(int r, int L, int R) {
  if (L > R) return 0;
  if (a[r].L == L && a[r].R == R) return a[r].Max;
  if (R <= a[r].Mid())
    return Query(r << 1, L, R);
  else if (L > a[r].Mid())
    return Query(r << 1 | 1, L, R);
  else {
    double ans1 = Query(r << 1, L, a[r].Mid());
    double ans2 = Query(r << 1 | 1, a[r].Mid() + 1, R);
    return max(ans1, ans2);
  }
}
void Update(int r, int pos, double num) {
  if (a[r].L == a[r].R && a[r].L == pos) {
    a[r].Max = num;
    return;
  }
  if (pos <= a[r].Mid())
    Update(r << 1, pos, num);
  else
    Update(r << 1 | 1, pos, num);
  a[r].Max = max(a[r << 1].Max, a[r << 1 | 1].Max);
}
int main() {
  int n;
  long long r, h;
  while (scanf("%d", &n) != EOF) {
    for (int i = 1; i <= n; i++) {
      scanf("%I64d %I64d", &r, &h);
      v[i] = b[i] = 4 * atan(1.0) * h * r * r;
    }
    sort(b, b + n);
    int len = unique(b, b + n) - b;
    Build(1, 1, len);
    double ans = 0;
    for (int i = 1; i <= n; i++) {
      int pos = lower_bound(b, b + len, v[i]) - b;
      double res = Query(1, 1, pos - 1) + v[i];
      Update(1, pos, res);
      ans = max(ans, res);
    }
    printf("%.12f\n", ans);
  }
  return 0;
}
