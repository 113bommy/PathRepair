#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 233;
const int T = 314000000;
vector<int> a[maxn], b[maxn], t[maxn];
bool cbe[maxn];
int vis[maxn];
int ru[maxn], num[maxn], val[maxn];
priority_queue<pair<long long, int> > q;
long long f[maxn], d[maxn], INF;
long long work(int x) {
  long long sum = val[x];
  for (int i = 0; i < a[x].size(); i++) {
    int y = a[x][i];
    sum += f[y];
  }
  return sum;
}
long long dfs(int x) {
  if (vis[x] == 1) return d[x];
  if (vis[x] == -1) return d[x] = -2;
  vis[x] = -1;
  for (int i = 0; i < t[x].size(); i++) {
    int y = t[x][i];
    if (!cbe[y]) continue;
    long long sum = val[y];
    for (int j = 0; j < a[y].size(); j++) {
      long long k = dfs(a[y][j]);
      if (k == -2) {
        vis[x] = 1;
        return d[x] = -2;
      }
      sum += k;
      if (sum > T) sum = T;
    }
    d[x] = max(d[x], sum);
  }
  vis[x] = 1;
  return d[x];
}
int main() {
  INF = 1;
  INF <<= 60;
  int m, n;
  cin >> m >> n;
  for (int i = 1; i <= n; i++) f[i] = 1, f[i] <<= 60;
  memset(d, 0, sizeof(d));
  for (int i = 1; i <= m; i++) {
    int x, len, cnt = 0;
    scanf("%d%d", &num[i], &len);
    t[num[i]].push_back(i);
    for (int j = 1; j <= len; j++) {
      int y;
      scanf("%d", &y);
      if (y == -1)
        cnt++;
      else {
        a[i].push_back(y);
        b[y].push_back(i);
        ru[i]++;
      }
    }
    if (!ru[i]) {
      q.push(make_pair(-cnt, i));
      if (cnt < f[num[i]]) f[num[i]] = cnt;
      if (cnt > d[num[i]]) d[num[i]] = cnt;
    }
    val[i] = cnt;
  }
  memset(cbe, 0, sizeof(cbe));
  memset(vis, 0, sizeof(vis));
  while (!q.empty()) {
    int x = q.top().second;
    q.pop();
    x = num[x];
    if (vis[x]) continue;
    vis[x] = 1;
    for (int i = 0; i < b[x].size(); i++) {
      int y = b[x][i];
      ru[y]--;
      if (!ru[y]) {
        cbe[y] = 1;
        long long buf = work(y);
        if (buf > T) buf = T;
        if (buf < f[num[y]]) {
          f[num[y]] = buf;
          q.push(make_pair(-buf, y));
        }
      }
    }
  }
  memset(vis, 0, sizeof(vis));
  for (int i = 1; i <= n; i++)
    if (!vis[i]) dfs(i);
  for (int i = 1; i <= n; i++) {
    long long x = f[i], y = d[i];
    if (x == INF) x = -1, y = -1;
    printf("%d %d\n", x, y);
  }
  return 0;
}
