#include <bits/stdc++.h>
const int maxn = 5010 * 2;
using namespace std;
struct node {
  int st;
  int en;
  int flow, cost;
  int next;
} E[101000];
int num;
int p[maxn];
void init() {
  memset(p, -1, sizeof p);
  num = 0;
}
void add(int st, int en, int flow, int cost) {
  E[num].st = st;
  E[num].en = en;
  E[num].flow = flow;
  E[num].cost = cost;
  E[num].next = p[st];
  p[st] = num++;
  E[num].st = en;
  E[num].en = st;
  E[num].flow = 0;
  E[num].cost = -cost;
  E[num].next = p[en];
  p[en] = num++;
}
int n;
int pre[maxn];
int dis[maxn];
bool fg[maxn];
bool spfa(int st, int en) {
  for (int i = 0; i <= en; i++) fg[i] = 0, dis[i] = 0x3FFFFFFF, pre[i] = -1;
  queue<int> q;
  q.push(st);
  fg[st] = 1;
  dis[st] = 0;
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    fg[u] = 0;
    for (int i = p[u]; i + 1; i = E[i].next) {
      int v = E[i].en;
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
  if (dis[en] < 0x3FFFFFFF) return 1;
  return 0;
}
int solve(int st, int en) {
  int ans = 0;
  while (spfa(st, en)) {
    int d = 0x3FFFFFFF;
    for (int i = pre[en]; i + 1; i = pre[E[i].st]) d = min(d, E[i].flow);
    for (int i = pre[en]; i + 1; i = pre[E[i].st]) {
      E[i].flow -= d;
      E[i ^ 1].flow += d;
      ans += d * E[i].cost;
    }
  }
  return ans;
}
vector<int> last[100005];
vector<int> mod[100005];
int a[maxn];
int main() {
  init();
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  add(0, 1, 2, 0);
  for (int i = 1; i <= n; i++) {
    add(1, i * 2, 1, 0);
    add(i * 2, i * 2 + 1, 1, -1);
    add(i * 2 + 1, n * 2 + 2, 1, 0);
  }
  for (int i = n; i >= 1; i--) {
    for (int j = 0; j < 2 && j < last[a[i] + 1].size(); j++) {
      int pos = last[a[i] + 1].size() - j - 1;
      add(i * 2 + 1, last[a[i] + 1][pos] * 2, 1, 0);
    }
    for (int j = 0; j < 2 && j < last[a[i] - 1].size(); j++) {
      int pos = last[a[i] - 1].size() - j - 1;
      add(i * 2 + 1, last[a[i] - 1][pos] * 2, 1, 0);
    }
    for (int j = 0; j < 2 && j < mod[a[i] % 7].size(); j++) {
      int pos = mod[a[i] % 7].size() - j - 1;
      add(i * 2 + 1, mod[a[i] % 7][pos] * 2, 1, 0);
    }
    last[a[i]].push_back(i);
    mod[a[i] % 7].push_back(i);
  }
  int ans = solve(0, 2 * n + 2);
  printf("%d\n", -ans);
  return 0;
}
