#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
struct node {
  long long id, dis;
};
vector<node> G[maxn];
long long path[maxn], dis[maxn];
long long a[maxn], b[maxn];
void dfs(long long p, int d, long long s) {
  path[d] = p, dis[d] = s;
  if (d > 0) {
    int l = -1, r = d;
    while (l < r - 1) {
      int m = l + (r - l) / 2;
      if (dis[d] - dis[m] <= a[p])
        r = m;
      else
        l = m;
    }
    if (r < d) {
      if (r - 1 > -1) b[path[r - 1]]--;
      b[path[d - 1]]++;
    }
  }
  for (int i = 0; i < G[p].size(); i++) {
    node u = G[p][i];
    dfs(u.id, d + 1, s + u.dis);
  }
}
void get_ans(int p) {
  for (int i = 0; i < G[p].size(); i++) {
    node u = G[p][i];
    get_ans(u.id);
    b[p] += b[u.id];
  }
}
int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 2; i <= n; i++) {
    long long p, d;
    cin >> p >> d;
    G[p].push_back(node{i, d});
  }
  memset(b, 0, sizeof(b));
  dfs(1, 0, 0);
  get_ans(1);
  for (int i = 1; i <= n; i++) printf("%lld%c", b[i], i == n ? '\n' : ' ');
}
