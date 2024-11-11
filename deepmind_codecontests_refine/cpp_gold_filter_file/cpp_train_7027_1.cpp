#include <bits/stdc++.h>
using namespace std;
const int maxn = 300005;
const long long inf = 1 << 27;
const long long mod = 1e9 + 7;
struct point {
  long long x, y;
} p[maxn];
int x1[maxn], x2[maxn], Y1[maxn], y2[maxn];
bool cmp1(int a, int b) { return p[a].x < p[b].x; }
bool cmp2(int a, int b) { return p[a].x > p[b].x; }
bool cmp3(int a, int b) { return p[a].y < p[b].y; }
bool cmp4(int a, int b) { return p[a].y > p[b].y; }
int used[maxn];
int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= n; i++) {
    long long X1, X2, y1, Y2;
    scanf("%lld%lld%lld%lld", &X1, &y1, &X2, &Y2);
    p[i].x = X1 + X2;
    p[i].y = y1 + Y2;
    x1[i] = x2[i] = Y1[i] = y2[i] = i;
  }
  sort(x1 + 1, x1 + 1 + n, cmp1);
  sort(x2 + 1, x2 + 1 + n, cmp2);
  sort(Y1 + 1, Y1 + 1 + n, cmp3);
  sort(y2 + 1, y2 + 1 + n, cmp4);
  long long ans = 1LL << 62;
  int flag = 0;
  for (int a = 0; a <= k; a++) {
    for (int b = 0; b <= k; b++) {
      for (int c = 0; c <= k; c++) {
        for (int d = 0; d <= k; d++) {
          flag++;
          int cnt = 0;
          for (int i = 1; i <= a; i++)
            if (used[x1[i]] != flag) {
              used[x1[i]] = flag;
              cnt++;
            }
          for (int i = 1; i <= b; i++)
            if (used[x2[i]] != flag) {
              used[x2[i]] = flag;
              cnt++;
            }
          for (int i = 1; i <= c; i++)
            if (used[Y1[i]] != flag) {
              used[Y1[i]] = flag;
              cnt++;
            }
          for (int i = 1; i <= d; i++)
            if (used[y2[i]] != flag) {
              used[y2[i]] = flag;
              cnt++;
            }
          if (cnt != k) continue;
          long long maxx = -1LL << 62, minx = 1LL << 62, maxy = -1LL << 62,
                    miny = 1LL << 62;
          for (int i = 1; i <= n; i++)
            if (used[i] != flag) {
              maxx = max(p[i].x, maxx);
              minx = min(p[i].x, minx);
              maxy = max(p[i].y, maxy);
              miny = min(p[i].y, miny);
            }
          long long x = maxx - minx, y = maxy - miny;
          if (x % 2 == 1) x++;
          if (y % 2 == 1) y++;
          x = max(2LL, x);
          y = max(2LL, y);
          ans = min(ans, x * y);
        }
      }
    }
  }
  printf("%lld\n", ans / 4);
  return 0;
}
