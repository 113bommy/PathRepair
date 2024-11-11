#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-9;
const int INF = 1000000000;
const long long LINF = 4000000000000000000ll;
void prepare() {}
int n, k, h;
int m[100005], v[100005];
pair<pair<int, int>, int> lem[100005];
int ans[100005];
bool f(double t) {
  int cur = n - 1;
  for (int i = k; i > 0; i--) {
    double h0 = h * i;
    while (cur >= 0) {
      if (h0 / lem[cur].first.second < t + eps) break;
      cur--;
    }
    if (cur == -1) return false;
    ans[i - 1] = lem[cur].second;
    cur--;
  }
  return true;
}
bool solve() {
  scanf("%d%d%d", &n, &k, &h);
  for (int i = 0; i < n; i++) scanf("%d", &lem[i].first.first);
  for (int i = 0; i < n; i++) {
    scanf("%d", &lem[i].first.second);
    lem[i].second = i;
  }
  sort(lem, lem + n);
  double l = 0.0, r = 1e9 + 2.0;
  for (int it = 0; it < 100; it++) {
    double t = (l + r) * 0.5;
    if (f(t))
      r = t;
    else
      l = t;
  }
  f(l + eps);
  for (int i = 0; i < k; i++) printf("%d ", ans[i] + 1);
  printf("\n");
  return false;
}
int main() {
  prepare();
  while (solve())
    ;
  return 0;
}
