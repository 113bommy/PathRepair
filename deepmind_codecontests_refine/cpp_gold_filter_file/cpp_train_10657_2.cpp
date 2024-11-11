#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline void checkMax(T& a, const T& b) {
  if (a < b) a = b;
}
template <typename T>
inline void checkMin(T& a, const T& b) {
  if (a > b) a = b;
}
template <int MAX_DIM>
void LinearEquation(int n, double a[MAX_DIM][MAX_DIM], double b[MAX_DIM],
                    double x[MAX_DIM]) {
  int r;
  double p;
  for (int n___LINE__ = (n), i = 0; i < n___LINE__; ++i) {
    r = i;
    for (__typeof__(i + 1) f___LINE__ = (i + 1), t___LINE__ = (n - 1),
                           j = f___LINE__;
         j <= t___LINE__; ++j) {
      if (fabs(a[j][i]) > fabs(a[r][i])) r = j;
    }
    if (r != i)
      for (int n___LINE__ = (n), j = 0; j < n___LINE__; ++j) {
        swap(a[r][j], a[i][j]);
        swap(b[r], b[i]);
      }
    for (int n___LINE__ = (n), j = 0; j < n___LINE__; ++j)
      if (j != i) {
        p = -a[j][i] / a[i][i];
        for (int n___LINE__ = (n), k = 0; k < n___LINE__; ++k)
          a[j][k] += p * a[i][k];
        b[j] += p * b[i];
      }
  }
  for (int n___LINE__ = (n), i = 0; i < n___LINE__; ++i) x[i] = b[i] / a[i][i];
}
const int kMaxN = 110;
const int kMaxM = 5000 + 10;
const double eps = 1e-9;
double a[kMaxN][kMaxN], b[kMaxN], x[kMaxN];
int V, E;
int cnt[kMaxN][kMaxN];
int s[kMaxM], e[kMaxM], c[kMaxM];
bool used[kMaxN];
void dfs(int x) {
  used[x] = true;
  for (int n___LINE__ = (V), i = 0; i < n___LINE__; ++i)
    if ((!used[i]) && (cnt[x][i] > 0)) {
      dfs(i);
    }
}
int main() {
  scanf("%d%d", &V, &E);
  for (int n___LINE__ = (E), i = 0; i < n___LINE__; ++i)
    scanf("%d%d%d", s + i, e + i, c + i);
  do {
    memset(a, 0, sizeof(a));
  } while (0);
  do {
    memset(b, 0, sizeof(b));
  } while (0);
  do {
    memset(x, 0, sizeof(x));
  } while (0);
  do {
    memset(cnt, 0, sizeof(cnt));
  } while (0);
  do {
    memset(used, 0, sizeof(used));
  } while (0);
  for (int n___LINE__ = (E), i = 0; i < n___LINE__; ++i) {
    --s[i], --e[i];
    cnt[s[i]][e[i]]++;
    cnt[e[i]][s[i]]++;
  }
  dfs(0);
  if (!used[V - 1]) {
    for (int n___LINE__ = (E + 1), i = 0; i < n___LINE__; ++i) puts("0");
    return 0;
  }
  for (int n___LINE__ = (V), i = 0; i < n___LINE__; ++i)
    if (!used[i]) a[i][i] = 1.0;
  b[0] = 1.0;
  for (int n___LINE__ = (V - 1), i = 0; i < n___LINE__; ++i)
    if (used[i])
      for (int n___LINE__ = (V), j = 0; j < n___LINE__; ++j)
        if (i != j) {
          a[i][i] += cnt[i][j];
          a[i][j] -= cnt[i][j];
        }
  a[V - 1][V - 1] = 1.0;
  LinearEquation(V, a, b, x);
  double ans = 1e9, delta;
  for (int n___LINE__ = (E), i = 0; i < n___LINE__; ++i) {
    delta = fabs(x[e[i]] - x[s[i]]);
    if (delta > eps) checkMin(ans, c[i] / delta);
  }
  printf("%.9f\n", ans);
  for (int n___LINE__ = (E), i = 0; i < n___LINE__; ++i) {
    printf("%.9f\n", (x[s[i]] - x[e[i]]) * ans);
  }
  return 0;
}
