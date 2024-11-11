#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 2;
const int M = 1e5 + 2;
const int mod = 1e9 + 7;
const int inf = 1e9;
const long long INF = 1e18;
void data() { ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0); }
int n, m, p[2 * N], ans[2 * N], t[4 * N];
pair<pair<int, int>, int> k[2 * N];
pair<int, int> a[2 * N];
void add(int val, int v = 1, int l = 1, int r = n) {
  if (l == r) {
    t[v] = 1;
    return;
  }
  int m = (l + r) >> 1;
  if (val <= m)
    add(val, v << 1, l, m);
  else
    add(val, v << 1 | 1, m + 1, r);
  t[v] = t[v << 1] + t[v << 1 | 1];
}
int get(int pos, int v = 1, int l = 1, int r = n) {
  if (l == r) return p[l];
  int m = (l + r) >> 1;
  if (t[v << 1] >= pos)
    return get(pos, v << 1, l, m);
  else
    return get(pos - t[v << 1], v << 1 | 1, m + 1, r);
}
bool mysort(pair<int, int> a, pair<int, int> b) {
  if (a.first == b.first) return a.second > b.second;
  return a.first < b.first;
}
int main() {
  data();
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i].first);
    p[i] = a[i].first;
    a[i].second = i;
  }
  sort(a + 1, a + n + 1, mysort);
  scanf("%d", &m);
  for (int i = 1; i <= m; ++i) {
    scanf("%d %d", &k[i].first.first, &k[i].first.second);
    k[i].second = i;
  }
  sort(k + 1, k + m + 1);
  int cnt = n;
  for (int i = 1; i <= m; ++i) {
    for (int j = k[i - 1].first.first; j < k[i].first.first; ++j)
      add(a[cnt--].second);
    ans[k[i].second] = get(k[i].first.second);
    cerr << "OK\n";
    ;
  }
  for (int i = 1; i <= m; ++i) {
    printf("%d\n", ans[i]);
  }
}
