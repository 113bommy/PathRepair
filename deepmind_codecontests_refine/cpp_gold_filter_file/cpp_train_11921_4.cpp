#include <bits/stdc++.h>
using namespace std;
int g[800][800];
const int N = 4100;
const int M = 1100000;
const int inf = int(1e9);
int ed, st;
int num = 1, d[N], now[N];
int e[M], pre[M], last[N], f[M];
void insert(int x, int y, int z) {
  e[++num] = y, f[num] = z, pre[num] = last[x], last[x] = num;
  e[++num] = x, f[num] = 0, pre[num] = last[y], last[y] = num;
}
queue<int> q;
bool bfs() {
  memset(d, -1, sizeof(d));
  d[st] = 0;
  q.push(st);
  while (!q.empty()) {
    int now = q.front();
    for (int i = last[now]; i; i = pre[i])
      if (f[i] && d[e[i]] == -1) {
        d[e[i]] = d[now] + 1;
        q.push(e[i]);
      }
    q.pop();
  }
  if (d[ed] == -1) return 0;
  return 1;
}
int dfs(int x, int incf) {
  if (x == ed) return incf;
  int flow = 0, w;
  for (int i = now[x]; i; i = pre[i])
    if (f[i] && d[e[i]] == d[x] + 1) {
      w = dfs(e[i], min(incf - flow, f[i]));
      f[i] -= w, f[i ^ 1] += w;
      flow += w;
      if (f[i]) now[x] = i;
      if (flow == incf) return incf;
    }
  if (!flow) d[x] = -1;
  return flow;
}
int dinic() {
  int maxflow = 0;
  while (bfs()) {
    for (int i = st; i <= ed; i++) now[i] = last[i];
    maxflow += dfs(st, inf);
  }
  return maxflow;
}
const int MAXN = 10000005;
struct AhoCorasick {
  int nxt[MAXN][2], fail[MAXN], ed[MAXN], id[MAXN], lasted[MAXN];
  int root, L;
  int newnode() {
    for (int i = (ed[L] = 0); i < 2; i++) nxt[L][i] = -1;
    return L++;
  }
  void init() {
    L = 0;
    memset(id, 0, sizeof(id));
    root = newnode();
  }
  void add(string &buf, int val, int inid) {
    int now = root;
    for (int i = 0; i < (int)buf.size(); i++) {
      if (nxt[now][buf[i] - 'a'] == -1) nxt[now][buf[i] - 'a'] = newnode();
      now = nxt[now][buf[i] - 'a'];
    }
    ed[now] += val;
    id[now] = inid;
  }
  void build() {
    queue<int> q;
    fail[root] = root;
    for (int i = 0; i < 2; i++) {
      if (nxt[root][i] == -1)
        nxt[root][i] = root;
      else {
        fail[nxt[root][i]] = root;
        q.push(nxt[root][i]);
      }
    }
    while (!q.empty()) {
      int now = q.front();
      q.pop();
      for (int i = 0; i < 2; i++) {
        if (nxt[now][i] == -1)
          nxt[now][i] = nxt[fail[now]][i];
        else {
          fail[nxt[now][i]] = nxt[fail[now]][i];
          if (id[fail[nxt[now][i]]])
            lasted[nxt[now][i]] = fail[nxt[now][i]];
          else
            lasted[nxt[now][i]] = lasted[fail[nxt[now][i]]];
          ed[nxt[now][i]] += ed[fail[nxt[now][i]]];
          q.push(nxt[now][i]);
        }
      }
    }
  }
  int query(string &buf) {
    int now = root, res = 0;
    for (int i = 0; i < (int)buf.size(); i++) {
      now = nxt[now][buf[i] - 'a'];
      res += ed[now];
    }
    return res;
  }
  void myquery(string &buf, int inid) {
    int now = root;
    for (int i = 0; i < (int)buf.size(); i++) {
      now = nxt[now][buf[i] - 'a'];
      if (id[now]) g[inid][id[now]] = 1;
      if (lasted[now] != 0) g[inid][id[lasted[now]]] = 1;
    }
  }
} ac;
int n, ans, anszhi[800];
string s[800];
int main() {
  ios::sync_with_stdio(false);
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> s[i];
  ac.init();
  for (int i = 1; i <= n; i++) ac.add(s[i], 1, i);
  ac.build();
  for (int i = 1; i <= n; i++) ac.myquery(s[i], i);
  for (int k = 1; k <= n; k++)
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= n; j++) g[i][j] |= g[i][k] & g[k][j];
  st = 0;
  ed = 2 * n + 1;
  for (int i = 1; i <= n; i++) insert(st, i, 1), insert(i + n, ed, 1);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
      if (g[i][j] && i != j) insert(i, j + n, 1);
  cout << (n - dinic()) << endl;
  for (int i = 1; i <= n; i++)
    if (d[i] != -1 && d[i + n] == -1) anszhi[++ans] = i;
  sort(anszhi + 1, anszhi + 1 + ans);
  for (int i = 1; i <= ans - 1; i++) cout << anszhi[i] << " ";
  cout << anszhi[ans] << endl;
  return 0;
}
