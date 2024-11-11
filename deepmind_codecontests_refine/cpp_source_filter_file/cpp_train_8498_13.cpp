#include <bits/stdc++.h>
using namespace std;
const int N = 10010;
int k, n, m, l, r;
int mx, Ans[N << 1];
pair<int, int> a[N];
bool Cmp(pair<int, int> x, pair<int, int> y) {
  return x.first < y.first || (x.first == y.first && x.second > y.second);
}
int main() {
  scanf("%d%d%d", &n, &l, &r);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i].second), m += a[i].second;
  l = m - l;
  r = m - r;
  swap(l, r);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i].first);
  sort(a + 1, a + n + 1);
  for (int i = 1; i <= m; i++) Ans[i] = -1e9;
  for (int i = 1; i <= n; i++)
    for (int j = m; j >= 0; j--)
      Ans[j + a[i].second] = max(
          Ans[j + a[i].second],
          Ans[j] + a[i].first * (j + a[i].second >= l && j + a[i].second <= r));
  for (int i = 0; i <= m; i++) mx = max(mx, Ans[i]);
  cout << mx << endl;
  return 0;
}
