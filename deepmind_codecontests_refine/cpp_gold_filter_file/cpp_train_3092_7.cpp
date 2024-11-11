#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -f;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}
template <typename T>
inline void Max(T &a, T &b) {
  if (a < b) a = b;
}
template <typename T>
inline void Min(T &a, T &b) {
  if (a > b) a = b;
}
const double pi = (double)acos(-1.0);
const double eps = (double)1e-8;
const int INF = (int)0x3f3f3f3f;
const int MOD = (int)1e9 + 7;
const int MAXN = (int)1e3 + 10;
const int MAXM = (int)1e5 + 10;
int n, a, b;
int ans[MAXN][MAXN];
int gao(int x) {
  for (int i = 1; i < n - x + 1; i++) ans[i][i + 1] = ans[i + 1][i] = 1;
}
void work() {
  scanf("%d%d%d", &n, &a, &b);
  if (a > 1 && b != 1)
    printf("NO\n");
  else if (b > 1 && a != 1)
    printf("NO\n");
  else if (a > 1) {
    gao(a);
    printf("YES\n");
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        printf("%d", ans[i][j]);
      }
      printf("\n");
    }
  } else if (b > 1) {
    gao(b);
    printf("YES\n");
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        if (i != j)
          printf("%d", 1 - ans[i][j]);
        else
          printf("0");
      }
      printf("\n");
    }
  } else {
    if (n == 1) {
      printf("YES\n");
      printf("0\n");
    } else if (n == 2 || n == 3)
      printf("NO\n");
    else {
      printf("YES\n");
      for (int i = 1; i < n; i++) ans[i][i + 1] = ans[i + 1][i] = 1;
      for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
          printf("%d", ans[i][j]);
        }
        printf("\n");
      }
    }
  }
}
int main() {
  work();
  return 0;
}
