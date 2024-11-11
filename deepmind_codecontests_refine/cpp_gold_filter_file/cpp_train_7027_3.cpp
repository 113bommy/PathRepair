#include <bits/stdc++.h>
using namespace std;
int last[100002];
struct node {
  int x, y;
  int id;
} p[100002], pp[100002], ppp[100002];
bool cmp(node a, node b) { return a.x < b.x; }
bool cmp1(node a, node b) { return a.y < b.y; }
int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  int x1, x2, y1, y2;
  for (int i = 0; i < n; i++) {
    scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
    ppp[i].x = pp[i].x = p[i].x = x1 + x2;
    ppp[i].y = pp[i].y = p[i].y = y1 + y2;
    ppp[i].id = pp[i].id = p[i].id = i;
  }
  sort(p, p + n, cmp);
  sort(pp, pp + n, cmp1);
  long long ans = 1.5 * 1e18;
  long long ll = 1LL << 62;
  int cou = 0;
  for (int a = 0; a <= k; a++)
    for (int b = 0; b <= k; b++)
      for (int c = 0; c <= k; c++)
        for (int d = 0; d <= k; d++) {
          cou++;
          int cnt = 0;
          for (int i = 0; i < a; i++)
            if (last[(p[i].id)] != cou) last[(p[i].id)] = cou, cnt++;
          for (int i = 0; i < b; i++)
            if (last[(p[n - i - 1].id)] != cou)
              last[p[n - i - 1].id] = cou, cnt++;
          for (int i = 0; i < c; i++)
            if (last[pp[i].id] != cou) last[pp[i].id] = cou, cnt++;
          for (int i = 0; i < d; i++)
            if (last[pp[n - i - 1].id] != cou)
              last[pp[n - i - 1].id] = cou, cnt++;
          if (cnt != k) continue;
          long long Maxx = -1LL << 62, Maxy = -1LL << 62, Minx = 1LL << 62,
                    Miny = 1LL << 62;
          double L0 = 1.0 * p[a].x / 2;
          double R0 = 1.0 * p[n - 1 - b].x / 2;
          double L1 = 1.0 * pp[c].y / 2;
          double R1 = 1.0 * pp[n - 1 - d].y / 2;
          long long A = (long long)(R0 - L0 + 0.5);
          long long B = (long long)(R1 - L1 + 0.5);
          if (A == 0) ++A;
          if (B == 0) ++B;
          ans = min(ans, A * B);
          for (int i = 0; i < n; i++) {
            if (last[i] != cou) {
              Maxx = max(Maxx, ppp[i].x * 1LL);
              Minx = min(Minx, ppp[i].x * 1LL);
              Maxy = max(Maxy, ppp[i].y * 1LL);
              Miny = min(Miny, ppp[i].y * 1LL);
            }
          }
          long long x = Maxx - Minx, y = Maxy - Miny;
          if (x % 2 == 1) x++;
          if (y % 2 == 1) y++;
          x = max(x, 2LL);
          y = max(y, 2LL);
          ll = min(ll, x * y);
        }
  cout << ll / 4;
  return 0;
}
