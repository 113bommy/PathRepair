#include <bits/stdc++.h>
int inp() {
  char c = getchar();
  while (c < '0' || c > '9') c = getchar();
  int sum = 0;
  while (c >= '0' && c <= '9') {
    sum = sum * 10 + c - '0';
    c = getchar();
  }
  return sum;
}
int q[1000010], dis[10010], head[10010], flow[200010], nxt[200010], end[200010],
    value[200010], pre1[10010], pre2[10010];
bool inq[10010];
bool spfa(int s, int e) {
  int qf = 1;
  int qe = 0;
  q[++qe] = s;
  memset(dis, 0x3f, sizeof(dis));
  dis[s] = 0;
  while (qf <= qe) {
    int u = q[qf++];
    inq[u] = false;
    for (int x = head[u]; x != -1; x = nxt[x]) {
      if (flow[x] && dis[end[x]] > dis[u] + value[x]) {
        dis[end[x]] = dis[u] + value[x];
        pre1[end[x]] = u;
        pre2[end[x]] = x;
        if (!inq[end[x]]) {
          q[++qe] = end[x];
          inq[end[x]] = true;
        }
      }
    }
  }
  return (dis[e] <= 1e9);
}
int mcmf(int s, int e) {
  int ans = 0;
  int _f = 0;
  while (spfa(s, e)) {
    int cur = e;
    int sum = 0;
    int f = 2147483647;
    while (cur != s) {
      f = std::min(f, flow[pre2[cur]]);
      sum += value[pre2[cur]];
      cur = pre1[cur];
    }
    ans += f * sum;
    _f += f;
    cur = e;
    while (cur != s) {
      flow[pre2[cur]] -= f;
      flow[pre2[cur] ^ 1] += f;
      cur = pre1[cur];
    }
  }
  return ans;
}
int cou = -1;
void link(int a, int b, int f, int w) {
  nxt[++cou] = head[a];
  head[a] = cou;
  end[cou] = b;
  flow[cou] = f;
  value[cou] = w;
  nxt[++cou] = head[b];
  head[b] = cou;
  end[cou] = a;
  flow[cou] = 0;
  value[cou] = -w;
}
bool used[110][110], ans[110][110];
int edg[110][110];
int main() {
  memset(head, -1, sizeof(head));
  int n = inp();
  int m = inp();
  int s = 0;
  int e = 10000;
  int cnt = n;
  for (int i = 1; i <= n; i++)
    for (int j = 0; j <= n; j++) link(i, e, 1, j);
  for (int i = 1; i <= m; i++) {
    int u = inp();
    int v = inp();
    link(s, v, 1, 0);
    ans[u][v] = true;
    if (u > v) std::swap(u, v);
    used[u][v] = true;
  }
  for (int i = 1; i < n; i++)
    for (int j = i + 1; j <= n; j++) {
      if (used[i][j]) continue;
      cnt++;
      link(cnt, i, 1, 0);
      edg[i][j] = cou;
      link(cnt, j, 1, 0);
      link(s, cnt, 1, 0);
    }
  mcmf(s, e);
  for (int i = 1; i <= n; i++)
    for (int j = i + 1; j <= n; j++)
      if (!used[i][j]) {
        if (flow[edg[i][j]])
          ans[j][i] = true;
        else
          ans[i][j] = true;
      }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) printf("%d", ans[i][j]);
    putchar('\n');
  }
}
