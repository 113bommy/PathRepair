#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9 + 5;
const long long linf = 1e18 + 5;
const int N = 1e5 + 5;
const int M = 2e6 + 5;
int n, m, c, x, y, a[N], divs[M];
pair<int, int> ans[N];
vector<int> v[N];
vector<pair<int, int> > have[M];
void dfs(int root, int x, int t) {
  int cur = a[x];
  while (cur != 1) {
    if (!have[divs[cur]].empty()) ans[x] = max(ans[x], have[divs[cur]].back());
    have[divs[cur]].push_back(make_pair(x, t));
    int div_it = divs[cur];
    while (cur % div_it == 0) cur /= div_it;
  }
  for (__typeof((v[x]).begin()) it = (v[x]).begin(); it != (v[x]).end(); it++)
    if (*it != root) dfs(x, *it, t + 1);
  cur = a[x];
  while (cur != 1) {
    have[divs[cur]].pop_back();
    int div_it = divs[cur];
    while (cur % div_it == 0) cur /= div_it;
  }
}
void init() {
  memset(ans, -1, sizeof(ans));
  dfs(0, 1, 1);
}
int main() {
  ios ::sync_with_stdio(0);
  for (int i = 2; i <= M - 1; i++)
    if (!divs[i])
      for (int j = i; j < M; j += i)
        if (!divs[j]) divs[j] = i;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1; i <= n - 1; i++) {
    cin >> x >> y;
    v[x].push_back(y);
    v[y].push_back(x);
  }
  init();
  for (int i = 1; i <= m; i++) {
    cin >> c;
    if (c == 1) {
      cin >> x;
      cout << ans[x].second << '\n';
    } else {
      cin >> x >> y;
      a[x] = y;
      init();
    }
  }
  return 0;
}
