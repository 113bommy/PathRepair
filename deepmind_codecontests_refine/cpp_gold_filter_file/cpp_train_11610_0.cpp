#include <bits/stdc++.h>
using namespace std;
template <class T>
inline bool checkMax(T &a, const T &b) {
  return a < b ? a = b, 1 : 0;
}
template <typename T, typename... Args>
inline void checkMax(T &a, const Args... arg) {
  checkMax(a, max(arg...));
}
template <class T>
inline bool checkMin(T &a, const T &b) {
  return a > b ? a = b, 1 : 0;
}
template <typename T, typename... Args>
inline void checkMin(T &a, const Args... arg) {
  checkMin(a, min(arg...));
}
const int INF = 0x3f3f3f3f;
const long long llINF = 1e18;
const int MAXN = 1e3 + 5;
int n;
int vis[MAXN], a[MAXN];
double p[MAXN][MAXN], E[MAXN], prod[MAXN];
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) scanf("%lf", &p[i][j]), p[i][j] /= 100;
  if (n == 1) {
    printf("0\n");
    return 0;
  }
  for (int i = 1; i <= n; i++) E[i] = 1, prod[i] = 1 - p[i][n];
  vis[n] = 1;
  a[1] = n;
  for (int i = 1; i <= n; i++) {
    double minval = llINF;
    int pos = 0;
    for (int j = 1; j <= n; j++) {
      if (!vis[j] && E[j] / (1 - prod[j]) < minval) {
        pos = j;
        minval = E[j] / (1 - prod[j]);
      }
    }
    vis[pos] = 1;
    for (int j = 1; j <= n; j++)
      E[j] += E[pos] / (1 - prod[pos]) * p[j][pos] * prod[j],
          prod[j] *= (1 - p[j][pos]);
  }
  printf("%.8f\n", E[1] / (1 - prod[1]));
  return 0;
}
