#include <bits/stdc++.h>
using namespace std;
const int N = 300005;
int n, u;
int e[N];
double ans = -1;
int search(int l, int r, int k) {
  int m, p = -1;
  while (l <= r) {
    m = (l + r) / 2;
    if (e[m] <= k) {
      p = m;
      l = m + 1;
    } else
      r = m - 1;
  }
  return p;
}
void solve() {
  for (int i = 0; i < n - 2; i++) {
    int k = search(i + 2, n - 1, e[i] + u);
    if (k == -1) continue;
    ans = max(ans, 1.0 * (e[k] - e[i + 1]) / (e[k] - e[i]));
  }
  if (ans > 0)
    printf("%.9f\n", ans);
  else
    puts("-1");
}
int main() {
  cin >> n >> u;
  for (int i = 0; i < n; i++) {
    cin >> e[i];
  }
  solve();
  return 0;
}
