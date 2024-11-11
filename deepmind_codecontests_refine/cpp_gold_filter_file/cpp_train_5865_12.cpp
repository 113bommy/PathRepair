#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-10;
const int inf = (int)1e9;
const int maxn = (int)1e5 + 10;
long long a[2 * maxn];
double res[maxn];
int main() {
  int n, l, v1, v2;
  scanf("%d%d%d%d", &n, &l, &v1, &v2);
  double dist = (l * 1. / (v1 + v2)) * v2;
  for (int i = 0; i < n; i++) scanf("%lld", &a[i]);
  for (int i = 0; i < n; i++) a[i + n] = a[i] + 2 * l;
  double st = a[0];
  int cur = 0;
  int i = 0, j = 1;
  while (a[j] < dist + a[0] - eps) cur++, j++;
  while (st < a[0] - eps + 2 * l) {
    if (a[i + 1] - st > a[j] - st - dist && j < 2 * n) {
      double len = a[j] - st - dist;
      res[cur] += len * 1. / (2 * l);
      st += len, j++, cur++;
    } else {
      double len = a[i + 1] - st;
      res[cur] += len * 1. / (2 * l);
      st += len, i++, cur--;
    }
  }
  for (int i = 0; i <= n; i++) printf("%.20lf\n", res[i]);
  return 0;
}
