#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}
double ans;
int n, cnt, C;
int head, tail;
int q[3005], d[3005], d2[3005];
bool vis[3005];
vector<int> e[3005];
void dfs(int x) {
  vis[x] = 1;
  for (int i = 0; i < e[x].size(); i++)
    if (!vis[e[x][i]]) {
      d2[e[x][i]] = d2[x] + 1;
      if (!d[e[x][i]]) {
        d[e[x][i]] = d[x] + 1;
        ans += 1.0 / d[e[x][i]];
      } else
        ans =
            ans + 1.0 / d2[e[x][i]] - 2.0 / (d[e[x][i]] + d2[e[x][i]] + C - 2);
      dfs(e[x][i]);
    }
  vis[x] = 0;
}
int main() {
  n = read();
  for (int i = 1; i <= n; i++) {
    int u = read(), v = read();
    u++;
    v++;
    e[u].push_back(v);
    e[v].push_back(u);
    d[u]++;
    d[v]++;
  }
  for (int i = 1; i <= n; i++)
    if (d[i] == 1) q[tail++] = i;
  while (head != tail) {
    int now = q[head];
    head++;
    for (int i = 0; i < e[now].size(); i++) {
      d[e[now][i]]--;
      if (d[e[now][i]] == 1) q[tail++] = e[now][i];
    }
  }
  C = n - tail;
  for (int i = 1; i <= n; i++) {
    memset(d, 0, sizeof(d));
    memset(d2, 0, sizeof(d2));
    d[i] = d2[i] = 1;
    dfs(i);
  }
  printf("%.10lf\n", ans + n);
  return 0;
}
