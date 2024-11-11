#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3fffffff;
const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};
const double eps = 1e-8;
const int maxn = 666;
const int N = 1010;
const int M = 2 * 10010;
const int inf = 1000000000;
struct Node {
  int f, t, c, w;
} e[M];
int next1[M], point[N], dis[N], q[N], pre[N], ne;
bool u[N];
void init();
void add_edge(int f, int t, int d1, int d2, int w);
void MCMF(int s, int t, int n, int &flow, int &cost);
char crossword[506];
void cptnext(int next[], char p[], int len) {
  int lolp = 0;
  next[1] = 0;
  for (int nocm = 2; nocm < len + 1; nocm++) {
    while (lolp > 0 && p[lolp] != p[nocm - 1]) lolp = next[lolp];
    if (p[lolp] == p[nocm - 1]) lolp++;
    next[nocm] = lolp;
  }
}
int main() {
  int n;
  while (scanf("%d", &n) != EOF) {
    scanf("%s", crossword);
    init();
    int m;
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
      char word[506];
      scanf("%s", word);
      int p;
      scanf("%d", &p);
      int prefix[506];
      cptnext(prefix, word, strlen(word));
      int nocm = 0;
      for (int j = 0; j < n; j++) {
        while (nocm > 0 && word[nocm] != crossword[j]) nocm = prefix[nocm];
        if (word[nocm] == crossword[j]) nocm++;
        if (nocm == strlen(word)) {
          add_edge(j - nocm + 1, j + 1, 1, 0, -p);
        }
      }
    }
    int x;
    scanf("%d", &x);
    for (int i = 0; i < n; i++) {
      add_edge(i, i + 1, x, 0, 0);
    }
    int flow = 0, cost = -inf;
    MCMF(0, n, n + 1, flow, cost);
    printf("%d\n", -cost);
  }
  return 0;
}
void init() {
  memset(point, -1, sizeof(point));
  ne = 0;
}
void add_edge(int f, int t, int d1, int d2, int w) {
  e[ne].f = f, e[ne].t = t, e[ne].c = d1, e[ne].w = w;
  next1[ne] = point[f], point[f] = ne++;
  e[ne].f = t, e[ne].t = f, e[ne].c = d2, e[ne].w = -w;
  next1[ne] = point[t], point[t] = ne++;
}
bool spfa(int s, int t, int n) {
  int i, tmp, l, r;
  memset(pre, -1, sizeof(pre));
  for (i = 0; i < n; ++i) dis[i] = inf;
  dis[s] = 0;
  q[0] = s;
  l = 0, r = 1;
  u[s] = true;
  while (l != r) {
    tmp = q[l];
    l = (l + 1) % (n + 1);
    u[tmp] = false;
    for (i = point[tmp]; i != -1; i = next1[i]) {
      if (e[i].c && dis[e[i].t] > dis[tmp] + e[i].w) {
        dis[e[i].t] = dis[tmp] + e[i].w;
        pre[e[i].t] = i;
        if (!u[e[i].t]) {
          u[e[i].t] = true;
          q[r] = e[i].t;
          r = (r + 1) % (n + 1);
        }
      }
    }
  }
  if (pre[t] == -1) return false;
  return true;
}
void MCMF(int s, int t, int n, int &flow, int &cost) {
  int tmp, arg;
  flow = cost = 0;
  while (spfa(s, t, n)) {
    arg = inf, tmp = t;
    while (tmp != s) {
      arg = min(arg, e[pre[tmp]].c);
      tmp = e[pre[tmp]].f;
    }
    tmp = t;
    while (tmp != s) {
      e[pre[tmp]].c -= arg;
      e[pre[tmp] ^ 1].c += arg;
      tmp = e[pre[tmp]].f;
    }
    flow += arg;
    cost += arg * dis[t];
  }
}
