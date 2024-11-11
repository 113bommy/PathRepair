#include <bits/stdc++.h>
using namespace std;
int l[100010], r[100010], a[100010];
int p;
double z[100010];
int get(int i) { return r[i] / p - (l[i] - 1) / p; }
double cal(int i) { return get(a[i]) * (1.0 / (r[a[i]] - l[a[i]] + 1)); }
double R(int i) { return cal(i) + cal(i + 1) - cal(i) * cal(i + 1); }
int main() {
  int n;
  double s = 1;
  cin >> n >> p;
  for (int i = 1; i <= n; i++) scanf("%d%d", l + i, r + i);
  for (int i = 1; i <= n; i++) a[i] = i;
  a[0] = n, a[n + 1] = 1;
  double ans = 0;
  for (int i = 1; i <= n; i++) ans += R(i);
  printf("%.10f\n", ans * 2000);
  return 0;
}
