#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 9;
int n, m, a[N];
vector<int> b[N];
long long cost(int x, int y) {
  long long ans(0);
  for (int p : b[x]) {
    if (p != 1 && a[p - 1] != x) ans += abs(a[p - 1] - x) - abs(a[p - 1] - y);
    if (p != m && a[p + 1] != x) ans += abs(a[p + 1] - x) - abs(a[p + 1] - y);
  }
  return ans;
}
int c[N], cnt;
long long calc(int x) {
  cnt = 0;
  long long delta(0);
  for (int p : b[x]) {
    if (p != 1 && a[p - 1] != x)
      c[cnt++] = a[p - 1], delta += abs(a[p - 1] - x);
    if (p != m && a[p + 1] != x)
      c[cnt++] = a[p + 1], delta += abs(a[p + 1] - x);
  }
  partial_sort(c, c + (cnt >> 1), c + cnt);
  int y = c[cnt >> 1];
  for (int i = 0; i < cnt; ++i) delta -= abs(y - c[i]);
  return delta;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n >> m;
  for (int i = 1; i <= m; ++i) cin >> a[i], b[a[i]].push_back(i);
  long long ans(0);
  for (int i = 1; i < m; ++i) ans += abs(a[i] - a[i + 1]);
  long long ma(0);
  for (int x = 1; x <= n; ++x) ma = max(ma, calc(x));
  cout << ans - ma;
}
