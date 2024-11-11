#include <bits/stdc++.h>
using namespace std;
vector<int> q;
int siz[200005];
int par[200005];
long long cost[200005];
vector<pair<int, long long>> MAP[200005];
void DFS(int x) {
  queue<int> qq;
  qq.push(x);
  while (!qq.empty()) {
    int now = qq.front();
    qq.pop();
    int len = MAP[now].size();
    for (int i = 0; i < len; i++) {
      int to = MAP[now][i].first;
      long long w = MAP[now][i].second;
      if (par[to] == -1) {
        cost[to] = w;
        par[to] = now;
        qq.push(to);
        q.push_back(to);
      }
    }
  }
}
int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int n;
    scanf("%d", &n);
    long long MAX = 0, MIN = 0;
    for (int i = 1; i <= 2 * n; i++) {
      par[i] = -1;
      siz[i] = 1;
      MAP[i].clear();
    }
    for (int i = 1; i <= 2 * n - 1; i++) {
      int u, v;
      long long w;
      scanf("%d %d %lld", &u, &v, &w);
      MAP[u].push_back(make_pair(v, w));
      MAP[v].push_back(make_pair(u, w));
    }
    par[1] = 0;
    q.clear();
    q.push_back(1);
    DFS(1);
    reverse(q.begin(), q.end());
    int len = q.size();
    for (int i = 0; i < len; i++) {
      int tmp = q[i];
      siz[par[tmp]] += siz[tmp];
      MAX += cost[tmp] * min(siz[tmp], 2 * n - siz[tmp]);
      MIN += cost[tmp] * (siz[tmp] & 1);
    }
    printf("%lld %lld\n", MIN, MAX);
  }
  return 0;
}
