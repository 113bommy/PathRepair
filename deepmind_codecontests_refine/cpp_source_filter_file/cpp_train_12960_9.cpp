#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int N = 105;
int read() {
  int s = 0, f = 1;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    s = s * 10 + c - '0';
    c = getchar();
  }
  return s * f;
}
int n, m;
long long Ans, f[N][N][2];
struct Point {
  int x, y;
} P[N];
bool cmp(Point A, Point B) { return A.x != B.x ? A.x < B.x : A.y < B.y; }
int main() {
  n = read();
  for (int i = 1; i <= n; i++) {
    P[i].x = read();
    P[i].y = read();
  }
  sort(P + 1, P + n + 1, cmp);
  P[1].x = -inf;
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= i; j++) {
      for (int k = 0; k < 2; k++) {
        Ans = max(Ans, f[i][j][k]);
        int pos = P[j].x + P[j].y * k;
        int Max = -inf, x = 0, y = 0;
        for (int l = i + 1; l <= n; l++) {
          for (int t = 0; t < 2; t++) {
            int p = P[l].x + P[l].y * t;
            if (Max < p) {
              Max = p;
              x = l;
              y = t;
            }
            f[l][x][y] =
                max(f[l][x][y], f[i][j][k] + min(P[l].y, p - pos) + Max - p);
          }
        }
      }
    }
  }
  printf("%lld", Ans);
  return 0;
}
