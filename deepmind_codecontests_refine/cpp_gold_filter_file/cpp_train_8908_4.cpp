#include <bits/stdc++.h>
using namespace std;
int v[60001], x[60001];
int n;
double ans;
bool check(double time) {
  int i;
  double low, high, l, r;
  low = x[0] - time * v[0];
  high = x[0] + time * v[0];
  for (i = 1; i < n; i++) {
    l = x[i] - time * v[i];
    r = x[i] + time * v[i];
    if (r < low || l > high) return false;
    low = max(l, low);
    high = min(r, high);
  }
  return true;
}
void dfs(double l, double r) {
  double mid;
  mid = (l + r) / 2;
  if (r - l <= 1e-7) {
    ans = l;
    return;
  } else {
    if (check(mid)) {
      dfs(l, mid);
    } else
      dfs(mid, r);
  }
}
int main() {
  int i;
  while (cin >> n) {
    for (i = 0; i < n; i++) cin >> x[i];
    for (i = 0; i < n; i++) cin >> v[i];
    dfs(0, 1e9);
    printf("%.10lf\n", ans);
  }
  return 0;
}
