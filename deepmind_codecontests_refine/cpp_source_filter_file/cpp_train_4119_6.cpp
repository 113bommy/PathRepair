#include <bits/stdc++.h>
using namespace std;
const int maxn = 222;
double p[maxn];
int n, x;
map<pair<int, int>, double> f;
double F(int l, int r, int v) {
  if (l == r) return f[make_pair(r - l + 1, v)] = p[v];
  if (f.find(make_pair(r - l + 1, v)) != f.end())
    return f[make_pair(r - l + 1, v)];
  double ret = 0.0;
  int mid = (l + r) / 2;
  for (int i = 0; i <= x; ++i)
    for (int j = 0; j <= x; ++j)
      if ((i ^ j) == v) ret += F(l, mid, i) * F(mid + 1, r, j);
  return f[make_pair(r - l + 1, v)] = ret;
}
int main() {
  scanf("%d%d", &n, &x);
  for (int i = 0; i <= x; ++i) scanf("%lf", &p[i]);
  printf("%.10lf\n", 1.0 - F(1, n, 0));
}
