#include <bits/stdc++.h>
using namespace std;
const int maxn = 100000 + 15;
struct Node {
  int a, b;
} a[maxn];
struct Ang {
  long long ans;
  int chose;
} ans[maxn], ang[maxn];
int n, w, s;
struct Point {
  long long x, y;
  Point() { x = y = 0; }
  Point(long long x, long long y) : x(x), y(y) {}
} sg[maxn];
int sum[maxn], sumsg;
int sed[maxn], maxx;
long long oldD[maxn];
int sh[maxn], sd[maxn], now[maxn];
int bs[maxn];
const Point operator-(const Point &a, const Point &b) {
  return Point(a.x - b.x, a.y - b.y);
}
const long long operator*(const Point &a, const Point &b) {
  return a.x * b.y - a.y * b.x;
}
bool cmp(Node a, Node b) { return a.a < b.a; }
int main() {
  scanf("%d%d", &n, &w);
  for (int i = 1; i <= n; i++)
    scanf("%d%d", &a[i].b, &a[i].a), maxx = max(maxx, a[i].b);
  sort(a + 1, a + n + 1, cmp);
  s = (int)(sqrt(n));
  for (int i = 1; i <= n; i++) {
    if (i % s == 1 || s == 1) {
      if (i != 1) {
        memset(sh, 0, sizeof(sh));
        for (int j = i - s; j < i; j++) sh[1]++, sh[a[j].b + 1]--;
        for (int j = 1; j <= maxx; j++) sh[j] += sh[j - 1];
        for (int j = 1; j <= maxx; j++) oldD[j] += 1ll * j * sh[j];
      }
      for (int j = 1; j <= sumsg; j++) sed[j] = sum[j] = 0;
      sumsg = 0;
      int endd = min(i + s - 1, n), sgg = endd - i + 1;
      for (int j = i; j <= endd; j++) bs[j - i + 1] = a[i].b;
      sort(bs + 1, bs + sgg + 1);
      bs[++sgg] = maxx;
      bs[0] = 0;
      for (int j = 0; j < sgg; j++)
        if (bs[j] != bs[j + 1]) {
          sumsg++;
          sd[sumsg] = bs[j + 1];
          now[sumsg] = sum[sumsg - 1] + 1;
          sum[sumsg] = sum[sumsg - 1];
          for (int k = bs[j] + 1; k <= bs[j + 1]; k++) {
            while (sum[sumsg] - sum[sumsg - 1] >= 2 &&
                   (sg[sum[sumsg]] - sg[sum[sumsg] - 1]) *
                           (Point(k, -oldD[k]) - sg[sum[sumsg]]) <=
                       0)
              sum[sumsg]--;
            sg[++sum[sumsg]] = Point(k, -oldD[k]);
          }
        }
    }
    for (int j = 1; j <= sumsg; j++) {
      while (now[j] < sum[j] && -sg[now[j]].y < -sg[now[j] + 1].y) now[j]++;
    }
    for (int j = 1; j <= sumsg && sd[j] <= a[i].b; j++) {
      sed[j]++;
      while (now[j] < sum[j] &&
             1ll * sed[j] * sg[now[j]].x - sg[now[j]].y <
                 1ll * sed[j] * sg[now[j] + 1].x - sg[now[j] + 1].y)
        now[j]++;
    }
    ang[i].chose = sg[now[1]].x;
    ang[i].ans = 1ll * sed[1] * sg[now[1]].x - sg[now[1]].y;
    for (int j = 2; j <= sumsg; j++)
      if (ang[i].ans < 1ll * sed[j] * sg[now[j]].x - sg[now[j]].y) {
        ang[i].chose = sg[now[j]].x;
        ang[i].ans = 1ll * sed[j] * sg[now[j]].x - sg[now[j]].y;
      }
  }
  for (int i = 0, j = 0; i <= a[n].a + 1; i++) {
    while (j < n && a[j + 1].a < i) j++;
    ans[i].chose = ang[j].chose;
    ans[i].ans = ang[j].ans + 1ll * (n - j) * i * w;
    printf("%I64d %d\n", ans[i].ans, ans[i].chose);
  }
  return 0;
}
