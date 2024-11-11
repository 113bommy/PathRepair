#include <bits/stdc++.h>
using namespace std;
template <class IT>
inline void cmax(IT &a, IT b) {
  if (a < b) a = b;
}
template <class IT>
inline void cmin(IT &a, IT b) {
  if (b < a) a = b;
}
template <class IT>
inline bool bmax(IT &a, IT b) {
  if (a < b) {
    a = b;
    return true;
  } else
    return false;
}
template <class IT>
inline bool bmin(IT &a, IT b) {
  if (a > b) {
    a = b;
    return true;
  } else
    return false;
}
namespace ACAM {
const int MAXN = 1005, ch = 14;
const char c0 = 'a';
struct node {
  int C[ch], f;
  long long x;
} V[MAXN];
int Q[MAXN], n;
inline void bug(int mc) {
  int v, c;
  for (v = (0); v <= (n); ++v) {
    cerr << "    " << ("v") << " = " << (v);
    cerr << "    " << ("V[v].f") << " = " << (V[v].f);
    cerr << "    " << ("V[v].x") << " = " << (V[v].x);
    for (c = (0); c < (mc); ++c) {
      cerr << "    " << ((char)(c + c0));
      cerr << "    " << (V[v].C[c]);
    }
    cerr << "\n";
  }
}
inline void init() {
  int c;
  n = 1;
  for (c = (0); c < (ch); ++c) V[0].C[c] = 1;
}
inline void add(char *s, int len, long long x) {
  int i, j, c, v = 1;
  for (i = (0); i < (len); ++i) {
    c = s[i] - c0;
    if (!V[v].C[c]) {
      V[v].C[c] = ++n;
      for (j = (0); j < (ch); ++j) V[n].C[j] = 0;
    }
    v = V[v].C[c];
  }
  V[v].x += x;
}
inline void build() {
  int ql = 0, qr = 0, v, c;
  Q[0] = 1;
  while (ql <= qr) {
    v = Q[ql++];
    V[v].x += V[V[v].f].x;
    for (c = (0); c < (ch); ++c) {
      if (V[v].C[c]) {
        Q[++qr] = V[v].C[c];
        V[V[v].C[c]].f = V[V[v].f].C[c];
      } else
        V[v].C[c] = V[V[v].f].C[c];
    }
  }
}
};  // namespace ACAM
const int N = 1005, L = 400005, M = 16384, ch = 14;
const long long inf = -1000000000000000000ll;
char S[L];
long long D[M][N], D2[M][N];
int V[M], X[M], Y[M];
pair<int, long long> T[N];
inline void ac() {
  int n, m, o, i, j, k, ix, s, c, x = 1, y;
  pair<int, long long> t;
  long long ans = inf;
  ACAM::init();
  scanf("%d", &k);
  while (k--) {
    scanf("%s%d", S, &n);
    ACAM::add(S, strlen(S), n);
  }
  ACAM::build();
  m = ACAM::n;
  scanf("%s", S);
  n = strlen(S);
  for (i = (0); i < (M); ++i)
    for (j = (1); j <= (m); ++j) D[i][j] = inf;
  for (i = (0); i < (M); ++i)
    for (j = (1); j <= (m); ++j) D2[i][j] = inf;
  D[0][1] = 0ll;
  for (i = (1); i <= (m); ++i) T[i].first = i;
  for (o = (0); o < (n); ++o) {
    if (S[o] == '?') {
      for (i = (0); i < (M); ++i) V[i] = 0;
      y = 0;
      for (ix = (1); ix <= (x); ++ix) {
        i = X[ix];
        for (k = (0); k < (ch); ++k)
          if (!(i >> k & 1) && !V[1 << k | i]) {
            V[1 << k | i] = 1;
            Y[++y] = 1 << k | i;
          }
      }
      for (ix = (1); ix <= (x); ++ix) {
        i = X[ix];
        for (j = (1); j <= (m); ++j)
          if (D[i][j] != inf) {
            t = T[j];
            cmax(D2[i][t.first], D[i][j] + t.second);
          }
      }
      for (ix = (1); ix <= (x); ++ix) {
        i = X[ix];
        for (j = (1); j <= (m); ++j)
          if (D2[i][j] != inf)
            for (k = (0); k < (ch); ++k)
              if (!(i >> k & 1)) {
                cmax(D[1 << k | i][ACAM::V[j].C[k]],
                     D2[i][j] + ACAM::V[ACAM::V[j].C[k]].x);
              }
      }
      x = y;
      for (ix = (1); ix <= (x); ++ix) X[ix] = Y[ix];
      for (i = (1); i <= (m); ++i) T[i] = make_pair(i, 0ll);
    } else {
      c = S[o] - 'a';
      for (i = (1); i <= (m); ++i)
        T[i].second += ACAM::V[T[i].first = ACAM::V[T[i].first].C[c]].x;
    }
  }
  for (ix = (1); ix <= (x); ++ix) {
    i = X[ix];
    for (j = (1); j <= (m); ++j)
      if (D[i][j] != inf) {
        t = T[j];
        cmax(ans, D[i][j] + t.second);
      }
  }
  printf("%lld", ans);
}
int main() {
  ac();
  return 0;
}
