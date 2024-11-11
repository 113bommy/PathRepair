#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9 + 9;
const int maxn = 1005;
const int maxm = 15;
const int maxl = 15;
const int chset = 4;
inline void uadd(int &a, int b) {
  a = ((a + b >= INF) ? (a + b - INF) : (a + b));
}
class ACAutomata {
 private:
  struct Node {
    int tag;
    int fail;
    int son[chset];
    Node() {
      tag = 0;
      fail = 0;
      memset(son, 0, sizeof(son));
      return;
    }
    inline void print() {
      printf("tag=%d\nfail=%d\n", tag, fail);
      puts("son:");
      for (int i = (0); i < (chset); ++i) printf("%d ", son[i]);
      puts("");
      return;
    }
  } node[maxm * maxl];
  int tot;
  int rt;
  inline int id(char c) {
    switch (c) {
      case 'A':
        return 0;
      case 'C':
        return 1;
      case 'G':
        return 2;
      case 'T':
        return 3;
      default:
        return -1;
    }
  }
  inline int buildNode() {
    node[tot] = Node();
    return tot++;
  }
  friend void solveDp(ACAutomata &ac);

 public:
  inline void init() {
    rt = tot = 0;
    node[tot++] = Node();
    return;
  }
  inline void insert(const char *s, int l) {
    int u = 0;
    for (int i = (0); i < (l); ++i) {
      char c = s[i];
      if (node[u].son[id(c)])
        u = node[u].son[id(c)];
      else
        u = node[u].son[id(c)] = buildNode();
    }
    node[u].tag = l;
    return;
  }
  inline void calcFail() {
    queue<int> q;
    for (int i = (0); i < (chset); ++i)
      if (node[rt].son[i])
        node[node[rt].son[i]].fail = 0, q.push(node[rt].son[i]);
    while (!q.empty()) {
      int u = q.front();
      node[u].tag = max(node[u].tag, node[node[u].fail].tag);
      q.pop();
      for (int i = (0); i < (chset); ++i) {
        int &v = node[u].son[i];
        if (v) {
          node[v].fail = node[node[u].fail].son[i];
          q.push(v);
        } else
          v = node[node[u].fail].son[i];
      }
    }
    return;
  }
  inline void print() {
    for (int u = (0); u < (tot); ++u) {
      printf("u=%d\n", u);
      node[u].print();
    }
    return;
  }
} ac;
int n, m, ans = 0;
int dp[maxn][maxm * maxl][maxl];
char s[maxl];
void solveDp(ACAutomata &ac) {
  dp[0][0][0] = 1;
  for (int i = (0); i < (n); ++i) {
    for (int u = (0); u < (ac.tot); ++u) {
      for (int k = (0); k < (maxl); ++k) {
        for (int j = (0); j < (chset); ++j) {
          int v = ac.node[u].son[j];
          if (ac.node[v].tag > k) {
            uadd(dp[i + 1][v][0], dp[i][u][k]);
          } else {
            if (k + 1 < maxl) uadd(dp[i + 1][v][k + 1], dp[i][u][k]);
          }
        }
      }
    }
  }
  for (int u = (0); u < (ac.tot); ++u) ans += dp[n][u][0];
  return;
}
int main() {
  scanf("%d%d", &n, &m);
  ac.init();
  for (int i = (0); i < (m); ++i) {
    scanf("%s", s);
    ac.insert(s, strlen(s));
  }
  ac.calcFail();
  solveDp(ac);
  printf("%d\n", ans);
  return 0;
}
