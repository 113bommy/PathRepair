#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 15;
map<pair<int, int>, int> H;
int t[N];
vector<int> adj[N];
int sum[N];
void update(int x, int add) {
  if (x == 0) return;
  while (x < N) sum[x] += add, x += x & (-x);
}
int q(int x) {
  int ret = 0;
  while (x) ret += sum[x], x = x & (x - 1);
  return ret;
}
int main() {
  int n, i, p, x, y, tot, j;
  scanf("%d%d", &n, &p);
  for (i = 0; i < n; ++i) {
    scanf("%d%d", &x, &y);
    if (x > y) swap(x, y);
    ++t[x], ++t[y];
    if (!H.count(make_pair(x, y))) adj[x].push_back(y);
    ++H[make_pair(x, y)];
  }
  long long ret = 0;
  for (i = 1; i <= n; ++i) update(t[i], 1);
  for (i = 1; i <= n; ++i) {
    update(t[i], -1);
    if (t[i] >= p)
      ret += n - i;
    else {
      tot = q(n) - q(p - t[i] - 1);
      ret += tot;
      for (j = 0; j < adj[i].size(); ++j) {
        x = adj[i][j];
        if (t[i] + t[x] < p) continue;
        y = H[make_pair(i, x)];
        if (t[x] + t[i] - y < p) --ret;
      }
    }
  }
  cout << ret << endl;
}
