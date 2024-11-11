#include <bits/stdc++.h>
using namespace std;
int m, n, k, t;
int a[200010];
struct node {
  int l, r, d;
} p[200010];
bool check(int x) {
  int o = a[m - x];
  vector<pair<int, int>> v;
  for (int i = 1; i <= k; i++)
    if (p[i].d > o) v.emplace_back(p[i].l, p[i].r);
  sort(v.begin(), v.end());
  long long sum = 0, ed = 0;
  for (auto i : v) {
    if (i.second <= ed) continue;
    if (ed < i.first) ed = i.first - 1;
    sum += i.second - ed;
    ed = i.second;
  }
  long long ans = (n + 1) + 2 * sum;
  return ans <= t;
}
int main() {
  cin >> m >> n >> k >> t;
  for (int i = 0; i < m; i++) cin >> a[i];
  for (int i = 1; i <= k; i++) cin >> p[i].l >> p[i].r >> p[i].d;
  sort(a, a + m);
  int l = 0, r = m;
  while (l < r) {
    int mid = (l + r + 1) >> 1;
    if (check(mid))
      l = mid;
    else
      r = mid - 1;
  }
  cout << l << endl;
  return 0;
}
