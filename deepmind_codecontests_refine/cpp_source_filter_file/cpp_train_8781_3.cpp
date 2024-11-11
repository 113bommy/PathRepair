#include <bits/stdc++.h>
using namespace std;
template <typename T, typename U>
inline void smin(T &a, U b) {
  if (a > b) a = b;
}
template <typename T, typename U>
inline void smax(T &a, U b) {
  if (a < b) a = b;
}
char s[333], t[333];
int dis[333], pre[333];
int adj[333][333], deg[333], cost[333][333], flow[333][333], C;
queue<int> q;
int maxflow(int s, int t) {
  int ans = 0, bot;
  while (1) {
    q = queue<int>();
    q.push(s);
    memset(dis, 0x3f, sizeof(dis));
    dis[s] = 0;
    while (!q.empty()) {
      int u = q.front();
      q.pop();
      for (int i = 0; i < deg[u]; i++) {
        int v = adj[u][i];
        if (flow[u][v] == 0) continue;
        if (dis[v] > dis[u] + cost[u][v]) {
          dis[v] = dis[u] + cost[u][v];
          q.push(v);
          pre[v] = u;
        }
      }
    }
    if (dis[t] == 0x3f3f3f3f) return ans;
    bot = 0x3f3f3f3f;
    for (int u = t; u != s; u = pre[u]) smin(bot, flow[pre[u]][u]);
    for (int u = t; u != s; u = pre[u]) {
      flow[pre[u]][u] -= bot;
      flow[u][pre[u]] += bot;
    }
    C += dis[t] * bot;
    ans += bot;
  }
}
int cnt[26];
int main() {
  scanf("%s", t);
  int n;
  cin >> n;
  for (int i = 0, sz = strlen(t); i < sz; i++) cnt[t[i] - 'a']++;
  int src = 0, tar = n + 26 + 1;
  for (int i = 0; i < 26; i++) {
    adj[n + i + 1][deg[n + i + 1]++] = tar;
    adj[tar][deg[tar]++] = n + i + 1;
    flow[n + i + 1][tar] = cnt[i];
  }
  int m;
  for (int i = 0; i < n; i++) {
    scanf("%s %d", s, &m);
    adj[src][deg[src]++] = i + 1;
    adj[i + 1][deg[i + 1]++] = src;
    flow[src][i + 1] = m;
    cost[src][i + 1] = i + 1;
    memset(cnt, 0, sizeof(cnt));
    for (int j = 0, sz = strlen(s); j < sz; j++) cnt[s[j] - 'a']++;
    for (int j = 0; j < 26; j++) {
      adj[i + 1][deg[i + 1]++] = n + j + 1;
      adj[n + j + i][deg[n + j + i]++] = i + 1;
      flow[i + 1][n + j + 1] = cnt[j];
    }
  }
  if (maxflow(src, tar) < strlen(t))
    puts("-1");
  else
    printf("%d\n", C);
  return 0;
}
