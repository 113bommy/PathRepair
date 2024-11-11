#include <bits/stdc++.h>
using namespace std;
const int N = 1005;
int n, m, p[N], v[N], lst[N];
double f[N];
bool check(double x) {
  for (int i = 1; i <= n; i++) f[i] = 1e19;
  f[0] = 0.0;
  for (int i = 0; i <= n; i++)
    for (int j = i + 1; j <= n; j++) {
      double y = f[i] + sqrt(abs(p[j] - p[i] - m)) * x - v[j];
      if (f[j] > y) {
        f[j] = y;
        lst[j] = i;
      }
    }
  if (f[n] < 0) return 0;
  return 1;
}
void print(int x) {
  if (x == 0) return;
  print(lst[x]);
  printf("%d ", x);
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) scanf("%d%d", &p[i], &v[i]);
  double l = 0, r = 1e6;
  while (abs(l - r) > 1e-9) {
    double mid = (l + r) / 2.0;
    if (check(mid))
      r = mid;
    else
      l = mid;
  }
  print(n);
  return 0;
}
