#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100;
const int INF = 0x3f3f3f3f;
char s[20];
char _s[20];
int tot;
int ty(char x[]) {
  if (x[0] == 'S')
    return 1;
  else if (x[0] == 'M')
    return 2;
  else if (x[0] == 'L')
    return 3;
  else if (x[1] == 'L')
    return 4;
  else if (x[2] == 'L')
    return 5;
  else
    return 6;
}
void pr(int x) {
  if (x == 1)
    printf("S\n");
  else if (x == 2)
    printf("M\n");
  else if (x == 3)
    printf("L\n");
  else if (x == 4)
    printf("XL\n");
  else if (x == 5)
    printf("XXL\n");
  else
    printf("XXXL\n");
}
int sz[10];
int ch[10];
struct Edge {
  int to, cap, flow;
};
struct Dinic {
  int s, t;
  vector<Edge> edges;
  vector<int> G[MAXN];
  int vis[MAXN];
  int d[MAXN];
  int cur[MAXN];
  vector<int> ans;
  void Init() {
    edges.clear();
    for (int i = 0; i < MAXN; ++i) G[i].clear();
  }
  void addedge(int from, int to, int cap) {
    edges.push_back(Edge{to, cap, 0});
    edges.push_back(Edge{from, 0, 0});
    int m = edges.size();
    G[from].push_back(m - 2);
    G[to].push_back(m - 1);
  }
  bool BFS() {
    memset(vis, 0, sizeof(vis));
    queue<int> Q;
    Q.push(s);
    d[s] = 0;
    vis[s] = 1;
    while (!Q.empty()) {
      int x = Q.front();
      Q.pop();
      for (int i = 0; i < (int)G[x].size(); ++i) {
        Edge& e = edges[G[x][i]];
        if (!vis[e.to] && e.cap > e.flow) {
          vis[e.to] = 1;
          d[e.to] = d[x] + 1;
          Q.push(e.to);
        }
      }
    }
    return vis[t];
  }
  int DFS(int x, int a) {
    if (x == t || a == 0) return a;
    int flow = 0, f;
    for (int& i = cur[x]; i < (int)G[x].size(); ++i) {
      Edge& e = edges[G[x][i]];
      if (d[x] + 1 == d[e.to] && (f = DFS(e.to, min(a, e.cap - e.flow))) > 0) {
        e.flow += f;
        edges[G[x][i] ^ 1].flow -= f;
        flow += f;
        a -= f;
        if (a == 0) break;
      }
    }
    return flow;
  }
  int Maxflow(int s, int t) {
    this->s = s;
    this->t = t;
    int flow = 0;
    while (BFS()) {
      memset(cur, 0, sizeof(cur));
      flow += DFS(s, INF);
    }
    return flow;
  }
} din;
int num[10];
int ans[100005];
int main() {
  int n;
  while (~scanf("%d", &sz[1])) {
    din.Init();
    memset(num, 0, sizeof(num));
    memset(ch, 0, sizeof(ch));
    for (int i = 2; i <= 6; ++i) scanf("%d", &sz[i]);
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
      scanf("%s", s);
      int len = strlen(s);
      s[len] = ',';
      tot = 0;
      int cc = 0;
      int t1;
      for (int j = 0; j <= len; ++j) {
        if (s[j] == ',') {
          _s[tot] = 0;
          cc++;
          t1 = ty(_s);
          tot = 0;
        } else
          _s[tot++] = s[j];
      }
      if (cc == 1) {
        sz[t1]--;
        ans[i] = t1;
      } else {
        num[t1]++;
        ans[i] = -t1;
      }
    }
    int fl = 0;
    for (int i = 1; i <= 6; ++i) {
      if (sz[i] < 0) {
        fl = 1;
        break;
      }
    }
    if (fl) {
      printf("NO\n");
      continue;
    }
    int tol = 0;
    int s = 0;
    int t = 13;
    for (int i = 2; i <= 6; ++i) {
      if (num[i]) {
        tol += num[i];
        din.addedge(s, i, num[i]);
        din.addedge(i, 6 + i - 1, num[i]);
        din.addedge(i, 6 + i, num[i]);
      }
    }
    for (int i = 1; i <= 6; ++i) {
      din.addedge(6 + i, t, sz[i]);
    }
    int flow = din.Maxflow(s, t);
    if (flow != tol) {
      printf("NO\n");
    } else {
      printf("YES\n");
      for (int j = 2; j <= 6; ++j)
        for (int i = 0; i < ((int)din.G[j].size()); ++i) {
          Edge& e = din.edges[din.G[j][i]];
          if (e.to == 6 + j - 1) {
            ch[j]++;
          }
        }
      for (int i = 1; i <= n; ++i) {
        if (ans[i] > 0)
          pr(ans[i]);
        else {
          ans[i] = -ans[i];
          if (ch[ans[i]])
            ch[ans[i]]--, pr(ans[i] - 1);
          else
            pr(ans[i]);
        }
      }
    }
  }
  return 0;
}
