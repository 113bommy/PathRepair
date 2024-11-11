#include <bits/stdc++.h>
using namespace std;
class Scanner {
 private:
  static const int BUFFER_SIZE = 10000;
  char buff[BUFFER_SIZE];
  int buffPos, buffLim;

 public:
  Scanner() {
    buffLim = fread(buff, 1, BUFFER_SIZE, stdin);
    buffPos = 0;
  }

 private:
  inline void flushBuff() {
    buffLim = fread(buff, 1, BUFFER_SIZE, stdin);
    if (buffLim == 0) {
      buff[buffLim++] = '\n';
    }
    buffPos = 0;
  }
  inline bool isWS(char t) { return t == ' ' || t == '\n'; }
  inline bool isDig(char t) { return t >= '0' && t <= '9'; }
  void nextPos() {
    buffPos++;
    if (buffPos == buffLim) {
      flushBuff();
    }
  }

 public:
  inline char getchar() {
    char ch = buff[buffPos];
    nextPos();
    return ch;
  }
  inline void next(char* s) {
    while (isWS(buff[buffPos])) {
      nextPos();
    }
    while (!isWS(buff[buffPos])) {
      *s = buff[buffPos];
      s++;
      nextPos();
    }
    *s = '\0';
  }
  inline void nextLine(char* s) {
    while (buff[buffPos] != '\n') {
      nextPos();
    }
    if (buff[buffPos] == '\n') {
      nextPos();
    }
    while (buff[buffPos] != '\n') {
      *s = buff[buffPos];
      s++;
      buffPos++;
    }
    *s = '\0';
  }
  inline int nextInt() {
    while (!isDig(buff[buffPos])) {
      nextPos();
    }
    int sign = (buff[buffPos] == '-') ? nextPos(), -1 : 1;
    int res = 0;
    while (isDig(buff[buffPos])) {
      res = res * 10 + buff[buffPos] - '0';
      nextPos();
    }
    return res * sign;
  }
  inline double nextDouble() {
    while (isWS(buff[buffPos])) {
      nextPos();
    }
    int sign = (buff[buffPos] == '-') ? nextPos(), -1 : 1;
    double res = 0;
    while (isDig(buff[buffPos])) {
      res = res * 10 + buff[buffPos] - '0';
      nextPos();
    }
    if (buff[buffPos] == '.') {
      nextPos();
      double ep = 1;
      while (isDig(buff[buffPos])) {
        ep *= 0.1;
        res += ep * (buff[buffPos] - '0');
        nextPos();
      }
    }
    return sign * res;
  }
  inline char nextChar() {
    while (isWS(buff[buffPos])) nextPos();
    char res = buff[buffPos];
    nextPos();
    return res;
  }
};
Scanner sc;
template <class T>
inline bool checkMin(T& a, T b) {
  return (a > b ? a = b, 1 : 0);
}
template <class T>
inline bool checkMax(T& a, T b) {
  return (a < b ? a = b, 1 : 0);
}
void ALERT(bool judgememt, const char* phrase) {
  if (judgememt) {
    puts(phrase);
    throw static_cast<string>("ALERT");
  }
}
bool alert(bool judgememt, const char* phrase) {
  if (judgememt) puts(phrase);
  return judgememt;
}
void preInit();
void init();
void solve();
int32_t main() {
  try {
    preInit();
    init();
    solve();
  } catch (string ss) {
  }
  return 0;
}
template <int N, class T>
class Tree {
 protected:
  vector<int> e[N];
  T val[N];

 public:
  void addEdge(int u, int v) {
    e[u].push_back(v);
    e[v].push_back(u);
  }
  void setVal(int u, T _val) { val[u] = _val; }
};
template <int N, class T>
class TreeLCA : public Tree<N, T> {
 protected:
  static const int B = 16;
  int fa[N][B], dep[N];
  void dfs(int u, int f) {
    dep[u] = dep[f] + 1;
    fa[u][0] = f;
    for (int i = 0; i < B - 1; i++) {
      fa[u][i + 1] = fa[fa[u][i]][i];
    }
    for (int v : this->e[u])
      if (v != f) {
        dfs(v, u);
      }
  }

 public:
  void init(int st) { dfs(st, st); }
  inline void up(int& u, int d) {
    for (int i = B - 1; i >= 0; i--) {
      if ((d >> i) & 1) {
        u = fa[u][i];
      }
    }
  }
  T lca(int u, int v) {
    if (dep[u] < dep[v]) {
      swap(u, v);
    }
    up(u, dep[u] - dep[v]);
    for (int i = B - 1; i >= 0; i--) {
      if (fa[u][i] != fa[v][i]) {
        u = fa[u][i];
        v = fa[v][i];
      }
    }
    return this->val[(u == v) ? u : fa[u][0]];
  }
};
template <int N>
class Dsu {
 protected:
  int p[N];

 public:
  Dsu() {
    for (int i = 0; i < N; i++) p[i] = i;
  }
  int get(int u) { return (u == p[u]) ? u : p[u] = get(p[u]); }
  void merge(int u, int v) { p[get(v)] = get(u); }
  bool query(int u, int v) { return get(u) == get(v); }
};
const int N = 2500;
int a[N][N];
int n;
void preInit() {
  n = sc.nextInt();
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) {
      a[i][j] = sc.nextInt();
    }
}
void init() {
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) {
      ALERT(a[i][j] != a[j][i], "NOT MAGIC");
    }
}
struct Edge {
  int u, v, w;
};
TreeLCA<N * 2, int> T;
vector<Edge> es;
Dsu<N * 2> st;
void solve() {
  for (int i = 0; i < n; i++)
    for (int j = 0; j < i; j++) es.push_back(Edge({i, j, a[i][j]}));
  sort(es.begin(), es.end(), [](Edge a, Edge b) { return a.w < b.w; });
  int nodeCnt = n;
  for (Edge e : es) {
    if (!st.query(e.u, e.v)) {
      T.setVal(nodeCnt, e.w);
      T.addEdge(nodeCnt, st.get(e.u));
      T.addEdge(nodeCnt, st.get(e.v));
      st.merge(nodeCnt, e.u);
      st.merge(nodeCnt, e.v);
      nodeCnt++;
    }
  }
  T.init(nodeCnt - 1);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < i; j++) {
      ;
      ;
      ;
      ALERT(a[i][j] > T.lca(i, j), "NOT MAGIC");
    }
  puts("MAGIC");
}
