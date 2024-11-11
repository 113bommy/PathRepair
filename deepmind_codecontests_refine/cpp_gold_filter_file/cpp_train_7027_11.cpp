#include <bits/stdc++.h>
using namespace std;
const int N = 100111;
struct point {
  int x, y, id;
} px[N], py[N];
int n, k;
long long ans = 1LL << 62;
bool del[N];
bool cmpx(point a, point b) { return a.x < b.x; }
bool cmpy(point a, point b) { return a.y < b.y; }
void solve() {
  sort(px + 1, px + n + 1, cmpx);
  sort(py + 1, py + n + 1, cmpy);
  int dlt[20];
  dlt[0] = 0;
  for (int a = (0); a <= (k); a++)
    for (int b = (0); b <= (k - a); b++)
      for (int c = (0); c <= (k - a - b); c++) {
        int d = k - a - b - c, ct, i, lb, rb, db, ub;
        for (ct = 1, i = 1; ct <= a; i++)
          if (!del[px[i].id]) {
            del[px[i].id] = true;
            ct++;
            dlt[++dlt[0]] = px[i].id;
          }
        for (ct = 1, i = n; ct <= b; i--)
          if (!del[px[i].id]) {
            del[px[i].id] = true;
            ct++;
            dlt[++dlt[0]] = px[i].id;
          }
        for (ct = 1, i = 1; ct <= c; i++)
          if (!del[py[i].id]) {
            del[py[i].id] = true;
            ct++;
            dlt[++dlt[0]] = py[i].id;
          }
        db = py[i].y;
        for (ct = 1, i = n; ct <= d; i--)
          if (!del[py[i].id]) {
            del[py[i].id] = true;
            ct++;
            dlt[++dlt[0]] = py[i].id;
          }
        ub = py[i].y;
        for (i = 1; del[px[i].id]; i++)
          ;
        lb = px[i].x;
        for (i = n; del[px[i].id]; i--)
          ;
        rb = px[i].x;
        ans = min(ans, max((long long)(rb - lb), 2LL) *
                           max((long long)(ub - db), 2LL));
        for (int j = 1; j <= (dlt[0]); j++) del[dlt[j]] = false;
        dlt[0] = 0;
      }
  printf("%I64d\n", ans / 4);
}
int main() {
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= (n); i++) {
    int x1, y1, x2, y2;
    scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
    px[i].x = x1 + x2;
    px[i].y = y1 + y2;
    px[i].id = i;
    py[i].x = x1 + x2;
    py[i].y = y1 + y2;
    py[i].id = i;
  }
  solve();
  return 0;
}
