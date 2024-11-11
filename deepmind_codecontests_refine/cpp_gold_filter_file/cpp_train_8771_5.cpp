#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  long long x = 0, f = 1;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9')
    x = (x << 3) + (x << 1) + (c ^ 48), c = getchar();
  return x * f;
}
const long long N = 1e6 + 10, M = 1e6 + 10;
long long t, n, s;
vector<pair<long long, long long> > G[N];
long long cost[N], cnt[N];
void dfs(int u, int fa) {
  if (fa != -1 && G[u].size() == 1) cnt[u] = 1;
  for (auto i : G[u]) {
    if (i.first == fa) continue;
    cost[i.first] = i.second;
    dfs(i.first, u);
    cnt[u] += cnt[i.first];
  }
}
struct node {
  long long val, cnt;
  bool operator<(const node& n) const {
    return n.cnt * n.val - n.cnt * (n.val / 2) > cnt * val - cnt * (val / 2);
  }
};
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> t;
  while (t--) {
    cin >> n >> s;
    for (int i = 1; i <= n; i++) G[i].clear(), cost[i] = 0, cnt[i] = 0;
    for (int i = 1; i < n; i++) {
      int a, b, c;
      cin >> a >> b >> c;
      G[a].push_back({b, c});
      G[b].push_back({a, c});
    }
    dfs(1, -1);
    priority_queue<node> q;
    long long sum = 0, res = 0;
    for (int i = 2; i <= n; i++) {
      sum += cost[i] * cnt[i];
      q.push({cost[i], cnt[i]});
    }
    while (sum > s) {
      node t = q.top();
      q.pop();
      sum -= t.cnt * t.val - t.cnt * (t.val / 2);
      q.push({t.val / 2, t.cnt});
      res++;
    }
    cout << res << endl;
  }
  return 0;
}
