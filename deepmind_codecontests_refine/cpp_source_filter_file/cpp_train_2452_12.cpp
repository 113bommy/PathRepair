#include <bits/stdc++.h>
using namespace std;
int break_point() {
  char c;
  while ((c = getchar()) != '\n')
    ;
  return 0;
}
template <typename T>
void read_integer(T &r) {
  bool sign = 0;
  r = 0;
  char c;
  while (1) {
    c = getchar();
    if (c == '-') {
      sign = 1;
      break;
    }
    if (c != ' ' && c != '\n') {
      r = c - '0';
      break;
    }
  }
  while (1) {
    c = getchar();
    if (c == ' ' || c == '\n') break;
    r = r * 10 + (c - '0');
  }
  if (sign) r = -r;
}
inline long long binpow(long long a, long long b, long long mod) {
  long long res = 1;
  while (b) {
    if (b & 1) {
      res *= a;
      res %= mod;
      b--;
    } else {
      a *= a;
      a %= mod;
      b >>= 1;
    }
  }
  return res;
}
inline long long binpow(long long a, long long b) {
  long long res = 1;
  while (b) {
    if (b & 1) {
      res *= a;
      b--;
    } else {
      a *= a;
      b >>= 1;
    }
  }
  return res;
}
inline int getbit(int x, int b) { return (x >> b) & 1; }
inline long long getbit(long long x, int b) { return (x >> b) & 1; }
inline unsigned long long getbit(unsigned long long x, int b) {
  return (x >> b) & 1;
}
inline int setbit(int x, int b) { return x | (1 << b); }
inline void _setbit(int &x, int b) { x = setbit(x, b); }
inline long long setbit(long long x, int b) { return x | (1ll << b); }
inline void _setbit(long long &x, int b) { x = setbit(x, b); }
inline int unsetbit(int x, int b) { return x & (INT_MAX - (1 << b)); }
inline void _unsetbit(int &x, int b) { x = unsetbit(x, b); }
inline int countbit(int x) {
  x = x - ((x >> 1) & 0x55555555);
  x = (x & 0x33333333) + ((x >> 2) & 0x33333333);
  return ((x + (x >> 4) & 0xF0F0F0F) * 0x1010101) >> 24;
}
inline long long countbit(long long x) {
  int p1 = (x >> 32) & ((1ll << 32) - 1);
  int p2 = x & ((1ll << 32) - 1);
  return countbit(p1) + countbit(p2);
}
template <typename T>
void printbit(T x, int len) {
  for (int i = len - 1; i >= 0; i--) printf("%d", getbit(x, i));
}
int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a % b); }
template <typename A, typename B>
ostream &operator<<(ostream &stream, const pair<A, B> &p) {
  stream << "{" << p.first << "," << p.second << "}";
  return stream;
}
template <typename A>
ostream &operator<<(ostream &stream, const vector<A> &v) {
  stream << "[";
  for (auto itr = v.begin(); itr != v.end(); itr++) stream << *itr << " ";
  stream << "]";
  return stream;
}
template <typename A, typename B>
ostream &operator<<(ostream &stream, const map<A, B> &v) {
  stream << "[";
  for (auto itr = v.begin(); itr != v.end(); itr++) stream << *itr << " ";
  stream << "]";
  return stream;
}
template <typename A>
ostream &operator<<(ostream &stream, const set<A> &v) {
  stream << "[";
  for (auto itr = v.begin(); itr != v.end(); itr++) stream << *itr << " ";
  stream << "]";
  return stream;
}
template <typename A>
ostream &operator<<(ostream &stream, const stack<A> &v) {
  stack<A> st = v;
  stream << "[";
  while (!st.empty()) {
    stream << st.top() << " ";
    st.pop();
  }
  stream << "]";
  return stream;
}
template <typename A>
ostream &operator<<(ostream &stream, const priority_queue<A> &v) {
  priority_queue<A> q = v;
  stream << "[";
  while (!q.empty()) {
    stream << q.top() << " ";
    q.pop();
  }
  stream << "]";
  return stream;
}
template <typename A>
ostream &operator<<(ostream &stream, const queue<A> &v) {
  queue<A> q = v;
  stream << "[";
  while (!q.empty()) {
    stream << q.front() << " ";
    q.pop();
  }
  stream << "]";
  return stream;
}
void run();
int main() {
  srand(time(NULL));
  do {
    run();
    if (0) {
      0 ? printf("-------------------------------\n") : 0;
      0 ? printf("-------------------------------\n") : 0;
      0 ? break_point() : 0;
    }
  } while (0);
  return 0;
}
const int mod = 1e9 + 7;
const int N = 1003;
struct Edge {
  int a, b, c;
  int id;
  Edge(int _a, int _b, int _c, int _id) : a(_a), b(_b), c(_c), id(_id) {}
  int to(int from) { return from == a ? b : a; }
};
vector<int> g[N];
vector<Edge> E;
int u[N], TM = 1;
int p[N], tin[N], up[N], sdgfsgf;
int isBridge[N * 30];
void dfs(int v, int forbidden = -1, int p_id = -1) {
  u[v] = TM;
  tin[v] = up[v] = sdgfsgf++;
  for (int id : g[v]) {
    if (id == p_id || id == forbidden) continue;
    int to = E[id].to(v);
    if (u[to] != TM) {
      p[to] = id;
      dfs(to, forbidden, id);
      up[v] = min((up[v]), (up[to]));
      if (up[to] > tin[v]) isBridge[id] = TM;
    } else
      up[v] = min((up[v]), (tin[to]));
  }
}
void run() {
  int n, m;
  int s, t;
  scanf("%d%d%d%d", &n, &m, &s, &t);
  int a, b, c;
  for (int i = 0; i < m; ++i) {
    scanf("%d%d%d", &a, &b, &c);
    g[a].push_back(((int)E.size()));
    g[b].push_back(((int)E.size()));
    E.push_back(Edge(a, b, c, i + 1));
  }
  p[s] = -1;
  dfs(s);
  if (u[t] != TM)
    printf("0\n");
  else {
    vector<int> ids;
    int v = t;
    while (v != s) {
      ids.push_back(p[v]);
      v = E[p[v]].to(v);
    }
    int res = INT_MAX;
    int x = -1, y = -1;
    for (int id : ids) {
      TM++;
      dfs(s, id);
      if (u[t] != TM && res > E[id].c) {
        res = E[id].c;
        x = E[id].id;
        y = -1;
      } else {
        v = t;
        while (v != s) {
          if (isBridge[p[v]] == TM && res > E[id].c + E[p[v]].c) {
            res = E[id].c + E[p[v]].c;
            x = E[id].id;
            y = E[p[v]].id;
          }
          v = E[p[v]].to(v);
        }
      }
    }
    if (res == INT_MAX)
      printf("-1\n");
    else if (y == -1)
      printf("%d\n1\n%d\n", res, x);
    else
      printf("%d\n2\n%d %d\n", res, x, y);
  }
}
