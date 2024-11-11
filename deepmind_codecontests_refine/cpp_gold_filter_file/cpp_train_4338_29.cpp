#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 10;
const long long mod = 1e9 + 7;
const int INF = 1e9;
const double eps = 1e-6;
int n, m;
int a[maxn];
int b[maxn];
char s[maxn];
int main() {
  int an, bn, v;
  scanf("%d%d%d%d%d", &n, &m, &an, &bn, &v);
  for (int i = 0; i < an; i++) scanf("%d", &a[i]);
  for (int i = 0; i < bn; i++) scanf("%d", &b[i]);
  int Maxa = a[an - 1], Mina = a[0];
  int Maxb = b[bn - 1], Minb = b[0];
  int q;
  scanf("%d", &q);
  while (q--) {
    int sx, sy, ex, ey;
    scanf("%d%d%d%d", &ex, &ey, &sx, &sy);
    if (ex == sx)
      printf("%d\n", abs(sy - ey));
    else {
      int ans1 = 0, ans2 = 0;
      if (sy < a[0]) {
        ans1 = abs(sx - ex);
        ans1 += abs(sy - a[0]);
        ans1 += abs(ey - a[0]);
      } else if (sy > a[an - 1]) {
        ans1 = abs(sx - ex);
        ans1 += abs(sy - a[an - 1]);
        ans1 += abs(ey - a[an - 1]);
      } else {
        int pos = upper_bound(a, a + an, sy) - a;
        int pos1 = a[pos];
        int pos2 = a[pos - 1];
        ans1 = abs(sx - ex);
        ans1 += min(abs(sy - pos1) + abs(ey - pos1),
                    abs(sy - pos2) + abs(ey - pos2));
      }
      if (sy < b[0]) {
        ans2 = abs(sx - ex) / v;
        if (abs(sx - ex) % v) ans2++;
        ans2 += abs(sy - b[0]);
        ans2 += abs(ey - b[0]);
      } else if (sy > b[bn - 1]) {
        ans2 = abs(sx - ex) / v;
        if (abs(sx - ex) % v) ans2++;
        ans2 += abs(sy - b[bn - 1]);
        ans2 += abs(ey - b[bn - 1]);
      } else {
        int pos = upper_bound(b, b + bn, sy) - b;
        int pos1 = b[pos];
        int pos2 = b[pos - 1];
        ans2 = abs(sx - ex) / v;
        if (abs(sx - ex) % v) ans2++;
        ans2 += min(abs(sy - pos1) + abs(ey - pos1),
                    abs(sy - pos2) + abs(ey - pos2));
      }
      if (an == 0) ans1 = INF;
      if (bn == 0) ans2 = INF;
      printf("%d\n", min(ans1, ans2));
    }
  }
}
