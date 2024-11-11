#include <bits/stdc++.h>
using namespace std;
int a[101010], T[101010];
pair<int, int> mx[101010];
vector<pair<int, int> > add[101010];
vector<pair<double, int> > multi;
int main() {
  int k, n, m, t, r, v;
  cin >> k >> n >> m;
  for (int i = 1; i <= k; i++) scanf("%d", a + i);
  for (int i = 1; i <= n; i++) {
    scanf("%d%d%d", T + i, &r, &v);
    int t = T[i];
    if (t == 1)
      mx[r] = max(mx[r], make_pair(v, i));
    else if (t == 2)
      add[r].push_back(make_pair(v, i));
    else
      multi.push_back(pair<double, int>(-v, i));
  }
  for (int i = 1; i <= k; i++) {
    if (mx[i].first)
      add[i].push_back(pair<int, int>(mx[i].first - a[i], mx[i].second));
    sort(add[i].begin(), add[i].end(),
         [](pair<int, int> x, pair<int, int> y) { return x.first > y.first; });
    long long cur = a[i];
    for (pair<int, int> v : add[i]) {
      multi.push_back(
          pair<double, int>(-1.0 * (cur + v.first) / cur, v.second));
      cur += v.first;
    }
  }
  sort(multi.begin(), multi.end());
  if (multi.size() > m) multi.resize(m);
  vector<int> id;
  for (pair<double, int> x : multi) id.push_back(x.second);
  sort(id.begin(), id.end(), [](int u, int v) { return T[u] < T[v]; });
  printf("%d\n", id.size());
  for (int x : id) {
    printf("%d ", x);
  }
  puts("");
  return 0;
}
