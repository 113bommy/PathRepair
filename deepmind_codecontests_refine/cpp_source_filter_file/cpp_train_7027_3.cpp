#include <bits/stdc++.h>
using namespace std;
struct node {
  int x, y;
} p[100005];
bool cmp1(int a, int b) { return p[a].x < p[b].x; }
bool cmp2(int a, int b) { return p[a].x > p[b].x; }
bool cmp3(int a, int b) { return p[a].y < p[b].y; }
bool cmp4(int a, int b) { return p[a].y > p[b].y; }
int pos1[100005], pos2[100005], pos3[100005], pos4[100005];
int last[100005];
int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  for (int i = 0; i < n; i++) {
    int x1, y1, x2, y2;
    scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
    p[i].x = (x1 + x2);
    p[i].y = (y1 + y2);
    pos1[i] = pos2[i] = pos3[i] = pos4[i] = i;
  }
  sort(pos1, pos1 + n, cmp1);
  sort(pos2, pos2 + n, cmp2);
  sort(pos3, pos3 + n, cmp3);
  sort(pos4, pos4 + n, cmp4);
  int now = 0;
  long long ans = 1LL << 62;
  for (int a = 0; a <= k; a++)
    for (int b = 0; b <= k; b++)
      for (int c = 0; c <= k; c++)
        for (int d = 0; d <= k; d++) {
          now++;
          int cnt = 0;
          for (int i = 0; i < a; i++)
            if (last[pos1[i]] != now) last[pos1[i]] = now, cnt++;
          for (int i = 0; i < b; i++)
            if (last[pos2[i]] != now) last[pos2[i]] = now, cnt++;
          for (int i = 0; i < c; i++)
            if (last[pos3[i]] != now) last[pos3[i]] = now, cnt++;
          for (int i = 0; i < d; i++)
            if (last[pos4[i]] != now) last[pos4[i]] = now, cnt++;
          if (cnt != k) continue;
          long long Maxx = -1LL << 62, Maxy = -1LL << 62, Minx = 1LL << 62,
                    Miny = 1LL << 62;
          for (int i = 0; i < n; i++) {
            if (last[i] != now) {
              Maxx = max(Maxx, p[i].x * 1LL);
              Minx = min(Minx, p[i].x * 1LL);
              Maxy = max(Maxy, p[i].y * 1LL);
              Miny = min(Miny, p[i].y * 1LL);
            }
          }
          long long x = Maxx - Minx, y = Maxy - Miny;
          x = max(x, 1LL);
          y = max(y, 1LL);
          ans = min(ans, x * y);
        }
  printf("%lld\n", ans / 4);
}
