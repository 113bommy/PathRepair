#include <bits/stdc++.h>
using namespace std;
const int maxn = 100010;
vector<pair<int, int> > ask[maxn];
int n, m;
long long sum[maxn], ans[maxn];
int s[maxn], top, a[maxn];
inline double slope(int k, int j) {
  double yk = sum[k] - (double)k * a[k], yj = sum[j] - (double)j * a[j];
  return (yk - yj) / (a[k] - a[j]);
}
void init() {
  for (int i = 1; i <= n; ++i) scanf("%d", a + i), sum[i] = sum[i - 1] + a[i];
  for (int i = 0; i <= n; ++i) ask[i].clear();
  scanf("%d", &m);
  int l, r;
  for (int i = 0; i < m; ++i) {
    scanf("%d%d", &l, &r);
    ask[r].push_back(make_pair(l, i));
  }
}
void solve() {
  int top = 0;
  int l, r, mid, pos;
  for (int i = 1; i <= n; ++i) {
    while (top > 0 && a[s[top]] >= a[i]) --top;
    while (top > 1 && slope(s[top], i) >= slope(s[top - 1], i)) --top;
    s[++top] = i;
    for (vector<pair<int, int> >::iterator it = ask[i].begin();
         it != ask[i].end(); ++it) {
      l = lower_bound(s + 1, s + top + 1, i - it->first + 1) - s;
      r = top - 1, pos = i;
      while (l <= r) {
        mid = (l + r) >> 1;
        if (slope(s[mid], s[mid + 1]) <= it->first - i)
          pos = s[mid], r = mid - 1;
        else
          l = mid + 1;
      }
      ans[it->second] =
          sum[i] - sum[pos] + (long long)a[pos] * (it->first + pos - i);
    }
  }
  for (int i = 0; i < m; ++i) printf("%I64d\n", ans[i]);
}
int main() {
  while (scanf("%d", &n) != EOF) {
    init();
    solve();
  }
  return 0;
}
