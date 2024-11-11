#include <bits/stdc++.h>
const int N = 310;
const int inf = 0x3f3f3f3f;
using namespace std;
int n, m, k;
struct data {
  int x, y, r;
  data() {}
  data(int _x, int _y, int _r) : x(_x), y(_y), r(_r) {}
  bool operator<(const data &a) const {
    if (a.r != r) return r < a.r;
    if (a.x != x) return x < a.x;
    return y < a.y;
  }
} a[10000010];
int c[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
char s[N][N];
int main() {
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 1; i <= n; i++) scanf("%s", &s[i][1]);
  int cnt = 0;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
      if (s[i][j] == '.') continue;
      for (int r = 1; r <= min(n, m); r++) {
        bool f = 0;
        for (int k = 0; k < 4; k++) {
          int x = i + c[k][0] * r, y = j + c[k][1] * r;
          if (x <= 0 || x > n || y <= 0 || y > m) {
            f = 1;
            break;
          }
          if (s[x][y] != '*') f = 1;
        }
        if (f) continue;
        a[cnt++] = data(i, j, r);
      }
    }
  sort(a, a + cnt);
  if (k > cnt) {
    puts("-1");
    return 0;
  }
  printf("%d %d\n", a[k - 1].x, a[k - 1].y);
  for (int i = 0; i < 4; i++) {
    int x = a[k - 1].x + a[k - 1].r * c[i][0];
    int y = a[k - 1].y + a[k - 1].r * c[i][1];
    printf("%d %d\n", x, y);
  }
  return 0;
}
