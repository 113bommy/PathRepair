#include <bits/stdc++.h>
using namespace std;
template <typename N>
N gcd(N a, N b) {
  return b ? gcd(b, a % b) : a;
}
template <typename N>
inline int sgn(N a) {
  return a > 0 ? 1 : (a < 0 ? -1 : 0);
}
inline void gn(long long &x) {
  int sg = 1;
  char c;
  while (((c = getchar()) < '0' || c > '9') && c != '-')
    ;
  c == '-' ? (sg = -1, x = 0) : (x = c - '0');
  while ((c = getchar()) >= '0' && c <= '9') x = x * 10 + c - '0';
  x *= sg;
}
template <typename T, typename S>
inline bool upmin(T &a, const S &b) {
  return a > b ? a = b, 1 : 0;
}
template <typename T, typename S>
inline bool upmax(T &a, const S &b) {
  return a < b ? a = b, 1 : 0;
}
template <typename N, typename PN>
inline N flo(N a, PN b) {
  return a >= 0 ? a / b : -((-a - 1) / b) - 1;
}
template <typename N, typename PN>
inline N cei(N a, PN b) {
  return a > 0 ? (a - 1) / b + 1 : -(-a / b);
}
inline void gn(int &x) {
  long long t;
  gn(t);
  x = t;
}
inline void gs(char *s) { scanf("%s", s); }
inline void gc(char &c) {
  while ((c = getchar()) > 126 || c < 33)
    ;
}
inline void pc(char c) { putchar(c); }
inline long long sqr(long long a) { return a * a; }
inline double sqrf(double a) { return a * a; }
const int inf = 0x3f3f3f3f;
const double pi = 3.14159265358979323846264338327950288L;
const double eps = 1e-6;
int n, m;
vector<int> chd[333333];
int nei[333333];
int nein[333333];
bool vis[333333];
int qu[333333];
int q;
int tonei1[333333], tonein[333333];
int main() {
  gn(n);
  gn(m);
  for (int i = (1), _ed = (m + 1); i < _ed; i++) {
    int u, v;
    gn(u);
    gn(v);
    chd[u].push_back(v);
    chd[v].push_back(u);
    if (u == 1 && v == n || u == n && v == 1) {
      printf("1\n1 %d\n", n);
      return 0;
    }
    if (u == 1) {
      nei[v] = 1;
    }
    if (v == 1) {
      nei[u] = 1;
    }
    if (u == n) nein[v] = 1;
    if (v == n) nein[u] = 1;
  }
  for (auto v : chd[n]) {
    if (nei[v]) {
      printf("2\n1 %d %d\n", v, n);
      return 0;
    }
  }
  for (int u = (1), _ed = (n + 1); u < _ed; u++)
    if (nei[u]) {
      for (auto v : chd[u]) {
        if (nein[v]) {
          printf("3\n1 %d %d %d\n", u, v, n);
          return 0;
        }
      }
    }
  for (int u = (2), _ed = (n + 1); u < _ed; u++)
    if (nei[u]) {
      for (auto v : chd[u]) {
        if (v == 1) continue;
        if (!nei[v]) {
          printf("4\n1 %d %d %d %d\n", u, v, 1, n);
          return 0;
        }
      }
    }
  for (int u = (2), _ed = (n + 1); u < _ed; u++)
    if (nei[u]) {
      for (auto v : chd[u]) {
        if (v == 1) continue;
        tonei1[v] = u;
      }
    }
  for (int u = (2), _ed = (n + 1); u < _ed; u++)
    if (nein[u]) {
      for (auto v : chd[u]) {
        if (v == n) continue;
        tonein[v] = u;
      }
    }
  for (int u = (1), _ed = (n + 1); u < _ed; u++)
    if (tonei1[u] && tonein[u]) {
      printf("4\n1 %d %d %d %d\n", tonei1[u], u, tonein[u], n);
      return 0;
    }
  for (int u = (2), _ed = (n + 1); u < _ed; u++)
    if (nei[u] && !vis[u]) {
      q = 0;
      vis[u] = 1;
      qu[++q] = u;
      for (auto w : chd[u]) {
        if (w == 1) continue;
        vis[w] = 1;
        qu[++q] = w;
      }
      for (int i = (2), _ed = (q + 1); i < _ed; i++) {
        int x = qu[i];
        set<int> ne;
        for (auto t : chd[x]) {
          if (t == 1) continue;
          ne.insert(t);
        }
        for (int j = (1), _ed = (q + 1); j < _ed; j++) {
          if (j == i) continue;
          int t = qu[j];
          if (ne.count(t)) {
            ne.erase(t);
          } else {
            printf("5\n1 %d %d %d %d %d\n", x, u, t, x, n);
            return 0;
          }
        }
        if (!ne.empty()) {
          int y = *ne.begin();
          printf("5\n1 %d %d %d %d %d\n", u, x, y, u, n);
          return 0;
        }
      }
    }
  printf("-1\n");
  return 0;
}
