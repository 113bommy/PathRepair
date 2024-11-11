#include <bits/stdc++.h>
using namespace std;
const int maxn = 100;
const int inf = 1e9 + 7;
const long long INF = 1e15 + 7;
int pree[maxn], pren[maxn];
long long flow[maxn];
long long length[maxn], vis[maxn];
int cnt = 1;
int n, m, s, t;
long long max_flow = 0, min_cost = 0;
int head[maxn];
struct node {
  int v;
  int next;
  long long w;
  long long flow;
} e[maxn * 10];
void add(int u, int v, int w, int flow) {
  e[++cnt].next = head[u];
  e[cnt].v = v;
  e[cnt].flow = flow;
  head[u] = cnt;
  e[cnt].w = w;
  e[++cnt].next = head[v];
  e[cnt].v = u;
  e[cnt].flow = 0;
  head[v] = cnt;
  e[cnt].w = -w;
}
bool spfa() {
  for (int i = 0; i <= n; i++) {
    length[i] = inf;
    vis[i] = 0;
    flow[i] = inf;
  }
  queue<int> q;
  q.push(s);
  vis[s] = 1;
  length[s] = 0;
  pren[t] = -1;
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    vis[u] = 0;
    for (int i = head[u]; i; i = e[i].next) {
      int v = e[i].v;
      if (e[i].flow && length[u] + e[i].w < length[v]) {
        length[v] = length[u] + e[i].w;
        pree[v] = i;
        pren[v] = u;
        flow[v] = min(flow[u], e[i].flow);
        if (!vis[v]) {
          vis[v] = 1;
          q.push(v);
        }
      }
    }
  }
  return pren[t] != -1;
}
void MCMF() {
  while (spfa()) {
    max_flow += flow[t];
    min_cost += flow[t] * length[t];
    for (int i = t; i != s; i = pren[i]) {
      e[pree[i]].flow -= flow[t];
      e[pree[i] ^ 1].flow += flow[t];
    }
  }
}
string str, tmp;
void solve() {
  int a;
  cin >> n;
  cin >> str;
  cin >> m;
  s = 0, t = n + 1;
  for (int i = 0; i < m; i++) {
    cin >> tmp;
    cin >> a;
    int len = tmp.length();
    for (int j = 0; j <= n - len; j++) {
      int flag = 1;
      for (int k = 0; k < len; k++) {
        if (str[j + k] != tmp[k]) {
          flag = 0;
          break;
        }
      }
      if (flag) {
        add(j + 1, j + len + 1, -a, 1);
      }
    }
  }
  cin >> a;
  for (int i = 1; i <= n; i++) {
    add(i, i + 1, 0, a);
  }
  n++;
  add(s, 1, 0, a);
  MCMF();
  cout << -min_cost << endl;
}
int main() {
  ios_base::sync_with_stdio(0);
  int t = 1;
  while (t--) {
    solve();
  }
}
