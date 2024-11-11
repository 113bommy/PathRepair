#include <bits/stdc++.h>
using namespace std;
struct edge {
  int to, w, next;
} edge[200005];
int head[200005], ptr;
void add_edge(int from, int to, int w) {
  edge[++ptr].to = to;
  edge[ptr].next = head[from];
  edge[ptr].w = w;
  head[from] = ptr;
}
long long deep[200005], a[200005];
int ans[200005];
vector<pair<long long, int> > path;
int lowerBound(int n) {
  int L = 0, R = path.size() - 1;
  while (L != R) {
    int mid = (L + R) / 2;
    if (path[mid].first >= n)
      R = mid;
    else
      L = mid + 1;
  }
  return L - 1;
}
void dfs(int now) {
  ans[now]++;
  path.push_back(make_pair(deep[now], now));
  int pos = lowerBound(deep[now] - a[now]);
  if (pos >= 0) ans[path[pos].second]--;
  for (int p = head[now]; p; p = edge[p].next) {
    deep[edge[p].to] = deep[now] + edge[p].w;
    dfs(edge[p].to);
    ans[now] += ans[edge[p].to];
  }
  path.pop_back();
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 2; i <= n; i++) {
    int a, b;
    cin >> a >> b;
    add_edge(a, i, b);
  }
  dfs(1);
  for (int i = 1; i <= n; i++) cout << ans[i] - 1 << ' ';
}
