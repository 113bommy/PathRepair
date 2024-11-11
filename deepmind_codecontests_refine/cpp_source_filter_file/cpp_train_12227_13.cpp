#include <bits/stdc++.h>
using namespace std;
const int N = 500 + 10;
int n, m;
int v[N];
double ans = 0.0;
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; ++i) scanf("%d", &v[i]);
  int x, y, w;
  for (int i = 1; i <= m; ++i) {
    scanf("%d%d%d", &x, &y, &w);
    ans = max(ans, (double)v[x] / w + v[y] / w);
  }
  printf("%.10f\n", ans);
  return 0;
}
