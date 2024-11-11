#include <bits/stdc++.h>
void fre() {
  freopen("c://test//input.in", "r", stdin);
  freopen("c://test//output.out", "w", stdout);
}
template <class T>
inline void scand(T &x) {
  char c;
  x = 0;
  while ((c = getchar()) < '0')
    ;
  while (c >= '0' && c <= '9') x = x * 10 + (c - 48), c = getchar();
}
template <class T>
inline void gmax(T &a, T b) {
  if (b > a) a = b;
}
template <class T>
inline void gmin(T &a, T b) {
  if (b < a) a = b;
}
using namespace std;
const int N = 105, M = 0, L = 0, Z = 1e9 + 7, t30 = 1 << 30,
          maxint = 2147483647, ms31 = 522133279, ms63 = 1061109567,
          ms127 = 2139062143;
const double eps = 1e-8, PI = acos(-1.0);
struct A {};
map<int, int> mop;
int casenum, casei, inf;
int n, i, j, u, v;
int x1, Y1, x2, y2;
int a[N][N];
void stupid() {
  memset(a, 0, sizeof(a));
  for (i = 1; i <= n; i++) {
    scanf("%d%d%d%d", &x1, &Y1, &x2, &y2);
    for (u = x1; u <= x2; u++) {
      for (v = Y1; v <= y2; v++) {
        a[u][v]++;
      }
    }
  }
  int ans = 0;
  for (i = 1; i <= 100; i++) {
    for (j = 1; j <= 100; j++) ans += a[i][j];
  }
  printf("%d\n", ans);
}
void clever() {
  int ans = 0;
  for (i = 1; i <= n; i++) {
    scanf("%d%d%d%d", &x1, &Y1, &x2, &y2);
    ans += (x2 - x1 + 1) * (y2 - Y1 + 1);
  }
  printf("%d\n", ans);
}
int main() {
  while (~scanf("%d", &n)) {
    clever();
  }
  return 0;
}
