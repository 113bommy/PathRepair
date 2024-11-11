#include <bits/stdc++.h>
using namespace std;
struct node {
  int u, v, flow, cost, next;
  node() {}
  node(int u, int v, int flow, int cost, int next)
      : u(u), v(v), flow(flow), cost(cost), next(next) {}
} E[2000010];
int len;
int num;
int p[4010];
void init() {
  memset(p, -1, sizeof p);
  num = 0;
}
void add(int u, int v, int flow, int cost) {
  E[num] = node(u, v, flow, cost, p[u]);
  p[u] = num++;
  E[num] = node(v, u, 0, -cost, p[v]);
  p[v] = num++;
}
int pre[4010];
int dis[4010];
bool fg[4010];
bool spfa(int st, int en) {
  for (int i = 0; i <= en; i++) fg[i] = 0, dis[i] = 1e8, pre[i] = -1;
  queue<int> q;
  q.push(st);
  fg[st] = 1;
  dis[st] = 0;
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    fg[u] = 0;
    for (int i = p[u]; i + 1; i = E[i].next) {
      int v = E[i].v;
      if (E[i].flow && dis[v] > dis[u] + E[i].cost) {
        dis[v] = dis[u] + E[i].cost;
        pre[v] = i;
        if (!fg[v]) {
          fg[v] = 1;
          q.push(v);
        }
      }
    }
  }
  if (dis[en] < 1e8) return 1;
  return 0;
}
int solve(int st, int en) {
  int ans = 0;
  while (spfa(st, en)) {
    int d = 1e8;
    for (int i = pre[en]; i + 1; i = pre[E[i].u]) d = min(d, E[i].flow);
    for (int i = pre[en]; i + 1; i = pre[E[i].u]) {
      E[i].flow -= d;
      E[i ^ 1].flow += d;
      ans += d * E[i].cost;
    }
  }
  return ans;
}
int main(void) {
  init();
  char s[550];
  scanf("%d%s", &len, s + 1);
  int m;
  scanf("%d", &m);
  int st = 0, en = len + 1;
  char s1[200];
  int wi;
  while (m--) {
    scanf("%s%d", s1 + 1, &wi);
    int len1 = strlen(s1 + 1);
    for (int i = 1; i + len1 <= len + 1; i++) {
      if (s[i] == s1[1]) {
        bool flag = true;
        for (int j = 1; j < len1; j++) {
          if (s[i + j] != s1[j + 1]) {
            flag = false;
            break;
          }
        }
        if (flag) {
          add(i, i + len1, 1, -wi);
        }
      }
    }
  }
  int k;
  scanf("%d", &k);
  for (int i = 0; i <= len; i++) {
    add(i, i + 1, k, 0);
  }
  int ret = solve(st, en);
  printf("%d\n", -ret);
  return 0;
}
