#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9 + 5;
const long long linf = 1e18 + 5;
const int N = 1e5 + 5;
int n, m, ans[N];
pair<int, int> kd[N << 3];
map<int, int> M;
pair<pair<int, int>, pair<int, int> > a[N], b[N];
pair<int, int> update(int root, int bas, int son, int x, pair<int, int> k) {
  if (son < x or x < bas) return kd[root];
  if (x <= bas and son <= x) return kd[root] = k;
  return kd[root] =
             max(update((root + root), bas, ((bas + son) >> 1), x, k),
                 update((root + root + 1), ((bas + son) >> 1) + 1, son, x, k));
}
pair<int, int> query(int root, int bas, int son, int x, int y) {
  if (son < x or y < bas) return make_pair(0, 0);
  if (x <= bas and son <= y) return kd[root];
  return max(query((root + root), bas, ((bas + son) >> 1), x, y),
             query((root + root + 1), ((bas + son) >> 1) + 1, son, x, y));
}
int main() {
  ios ::sync_with_stdio(0);
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> a[i].first.first >> a[i].first.second >> a[i].second.first;
    a[i].second.second = i;
    M[a[i].second.first]++;
  }
  for (int i = 1; i <= m; i++) {
    cin >> b[i].first.first >> b[i].first.second >> b[i].second.first;
    b[i].second.second = i;
    M[b[i].second.first]++;
  }
  sort(a + 1, a + n + 1);
  sort(b + 1, b + m + 1);
  int cur = 0;
  for (__typeof((M).begin()) it = (M).begin(); it != (M).end(); it++)
    it->second = ++cur;
  for (int i = 1; i <= n; i++) a[i].second.first = M[a[i].second.first];
  for (int i = 1; i <= m; i++) b[i].second.first = M[b[i].second.first];
  int j = 1;
  for (int i = 1; i <= m; i++) {
    while (j <= n and a[j].first.first <= b[i].first.first) {
      update(1, 1, cur, a[j].second.first,
             make_pair(a[j].first.second, a[j].second.second));
      j++;
    }
    int l = M[b[i].second.first], r = cur;
    while (l < r) {
      int m = l + r >> 1;
      if (query(1, 1, cur, b[i].second.first, m).first >= b[i].first.second)
        r = m;
      else
        l = m + 1;
    }
    if (query(1, 1, cur, b[i].second.first, l).first >= b[i].first.second)
      ans[b[i].second.second] = query(1, 1, cur, b[i].second.first, l).second;
  }
  for (int i = 1; i <= m; i++) cout << ans[i] - !ans[i] << ' ';
  cout << '\n';
  return 0;
}
