#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
int unset[N];
int unfind(int a) {
  if (unset[a] < 0) return a;
  return unset[a] = unfind(unset[a]);
}
void un(int a, int b) {
  a = unfind(a);
  b = unfind(b);
  unset[b] += unset[a];
  unset[a] = b;
  return;
}
vector<int> edge[N];
vector<pair<int, int> > order;
int n, m, v[N], sum[N];
bool vis[N];
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &v[i]);
    order.push_back(make_pair(v[i], i));
  }
  memset(unset, -1, sizeof unset);
  sort(order.begin(), order.end());
  reverse(order.begin(), order.end());
  int a, b;
  while (m--) {
    scanf("%d%d", &a, &b);
    edge[a].push_back(b);
    edge[b].push_back(a);
  }
  long long ans = 0;
  for (int i = 0; i < n; ++i) {
    int u = order[i].second;
    int cnt = 0;
    int s = 0;
    for (int j = 0; j < edge[u].size(); ++j) {
      int vv = edge[u][j];
      if (vis[vv]) {
        if (unfind(u) == unfind(vv)) continue;
        sum[++cnt] = -unset[unfind(vv)];
        s += -unset[unfind(vv)];
        un(u, vv);
      }
    }
    for (int j = 1; j <= cnt; ++j) {
      ans += 1LL * sum[j] * 1LL * (s - sum[j]) * v[u];
    }
    ans += 1LL * s * v[u] * 2;
    vis[u] = true;
  }
  double opt = ans;
  opt /= n;
  opt /= n - 1;
  printf("%f\n", opt);
}
