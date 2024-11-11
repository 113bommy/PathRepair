#include <bits/stdc++.h>
template <class T>
__inline__ __attribute__((always_inline)) bool chkmax(T &a, const T &b) {
  return a < b ? ((a = b), 1) : 0;
}
template <class T>
__inline__ __attribute__((always_inline)) bool chkmin(T &a, const T &b) {
  return a > b ? ((a = b), 1) : 0;
}
template <class T>
__inline__ __attribute__((always_inline)) T mymax(const T &a, const T &b) {
  return a > b ? a : b;
}
template <class T>
__inline__ __attribute__((always_inline)) T mymin(const T &a, const T &b) {
  return a < b ? a : b;
}
template <class T>
__inline__ __attribute__((always_inline)) T myabs(const T &a) {
  return a > 0 ? a : -a;
}
const int INF = 0X3F3F3F3F;
const double EPS = 1E-8, PI = acos(-1.0);
const int MAXN = 40 + 5, MASK = 1 << 20;
int deg[MAXN], n, m;
bool G[MAXN][MAXN];
__inline__ __attribute__((always_inline)) long long A() { return 1LL << n; }
int bad[MASK];
long long f[MASK], g[MASK];
bool tp[MASK];
__inline__ __attribute__((always_inline)) void calc(int l, int r,
                                                    long long *f) {
  int x = r - l;
  memset(tp, 1, sizeof tp);
  for (int i = (0), iend = (x); i < iend; ++i) {
    for (int j = (i + 1), jend = (x); j < jend; ++j) {
      if (G[i + l][j + l]) {
        tp[(1 << i) + (1 << j)] = 0;
      }
    }
  }
  for (int i = (0), iend = (x); i < iend; ++i) {
    for (int S = (1), Send = (1 << x); S < Send; ++S) {
      if ((S >> i) & 1) {
        tp[S] &= tp[S ^ (1 << i)];
      }
    }
  }
  for (int S = (0), Send = (1 << x); S < Send; ++S) {
    f[S] = tp[S];
  }
  for (int i = (0), iend = (x); i < iend; ++i) {
    for (int S = (1), Send = (1 << x); S < Send; ++S) {
      if ((S >> i) & 1) {
        f[S] += f[S ^ (1 << i)];
      }
    }
  }
}
__inline__ __attribute__((always_inline)) long long B() {
  int x = n / 2, y = n - x;
  calc(x, n, g);
  calc(0, x, f);
  for (int i = (0), iend = (x); i < iend; ++i) {
    for (int j = (x), jend = (n); j < jend; ++j) {
      if (G[i][j]) {
        bad[1 << i] |= 1 << (j - x);
      }
    }
  }
  long long ret = 0;
  for (int S = (0), Send = (1 << x); S < Send; ++S) {
    if (tp[S]) {
      for (int i = (0), iend = (x); i < iend; ++i) {
        if ((S >> i) & 1) {
          bad[S] |= bad[1 << i];
        }
      }
      int T = (1 << y) - 1 - bad[S];
      ret += g[T];
    }
  }
  return ret;
}
bool vis[MAXN];
void DFS1(int u) {
  vis[u] = 1;
  for (int i = (0), iend = (n); i < iend; ++i) {
    if (!vis[i] && G[u][i]) {
      DFS1(i);
    }
  }
}
__inline__ __attribute__((always_inline)) long long C() {
  int ret = 0;
  for (int i = (0), iend = (n); i < iend; ++i) {
    if (!vis[i]) {
      DFS1(i);
      ++ret;
    }
  }
  return 1LL << ret;
}
__inline__ __attribute__((always_inline)) long long D() {
  int ret = 0;
  for (int i = (0), iend = (n); i < iend; ++i) {
    if (!deg[i]) {
      ++ret;
    }
  }
  return 1LL << ret;
}
int col[MAXN];
bool ok;
void DFS2(int u) {
  for (int i = (0), iend = (n); i < iend; ++i) {
    if (G[u][i]) {
      if (!col[i]) {
        col[i] = -col[u];
        DFS2(i);
      } else if (col[i] == col[u]) {
        ok = 0;
      }
    }
  }
}
__inline__ __attribute__((always_inline)) long long E() {
  long long ret = 1;
  for (int i = (0), iend = (n); i < iend; ++i) {
    if (!col[i]) {
      ok = 1;
      col[i] = 1;
      DFS2(i);
      ret *= ok * 2;
    }
  }
  return ret;
}
__inline__ __attribute__((always_inline)) long long F() {
  return (1LL << n) * !m;
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = (1), iend = (m); i <= iend; ++i) {
    int u, v;
    scanf("%d%d", &u, &v);
    --u, --v;
    G[u][v] = G[v][u] = 1;
    ++deg[u], ++deg[v];
  }
  printf("%lld\n", A() - B() * 2 - C() + D() * 2 + E() - F());
  return 0;
}
