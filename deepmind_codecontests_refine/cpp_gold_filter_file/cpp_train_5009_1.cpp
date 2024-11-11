#include <bits/stdc++.h>
using namespace std;
struct he {
  long long x, y, c;
} p[200005], a[200005], a1[200005];
long long b[200005], d[200005];
int n;
long long ans, f[200005][2];
bool cmp(he a, he b) { return a.c < b.c; }
long long dis(long long x1, long long y1, long long x2, long long y2) {
  return fabs(x1 - x2) + fabs(y1 - y2);
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%lld%lld", &p[i].x, &p[i].y);
    p[i].c = max(p[i].x, p[i].y);
  }
  sort(p + 1, p + 1 + n, cmp);
  int num = 0;
  for (int i = 1; i <= n; i++) {
    int j, cnt = 0;
    for (j = i; j <= n && p[j].c == p[i].c; j++) {
      b[++cnt] = j;
    }
    long long tmp1 = -1, tmp = -1, tmp2 = -1, tmp3 = -1;
    for (int k = 1; k <= cnt; k++) {
      if (p[b[k]].x == p[i].c) {
        if (tmp == -1 || p[b[k]].y < tmp) tmp = p[b[k]].y;
        if (tmp2 == -1 || p[b[k]].y > tmp2) tmp2 = p[b[k]].y;
      }
      if (p[b[k]].y == p[i].c) {
        if (tmp1 == -1 || p[b[k]].x < tmp1) tmp1 = p[b[k]].x;
        if (tmp3 == -1 || p[b[k]].x > tmp3) tmp3 = p[b[k]].x;
      }
    }
    ++num;
    if (tmp == -1) {
      a[num].x = tmp1;
      a[num].y = p[i].c;
      a1[num].x = tmp3;
      a1[num].y = p[i].c;
    } else if (tmp1 == -1) {
      a[num].y = tmp;
      a[num].x = p[i].c;
      a1[num].y = tmp2;
      a1[num].x = p[i].c;
    } else {
      a[num].x = tmp1;
      a[num].y = p[i].c;
      a1[num].x = p[i].c;
      a1[num].y = tmp;
    }
    ans += dis(a[num].x, a[num].y, a1[num].x, a1[num].y);
    i = j - 1;
  }
  a[0] = (he){0, 0, 0};
  for (int i = 1; i <= num; i++) f[i][0] = f[i][1] = -1;
  f[0][0] = f[0][1] = 0;
  for (int i = 1; i <= num; i++) {
    if (a[i].x != -1) {
      if (f[i - 1][0] != -1) {
        if (f[i][0] == -1 ||
            f[i][0] >
                f[i - 1][0] + dis(a[i].x, a[i].y, a1[i - 1].x, a1[i - 1].y))
          f[i][0] = f[i - 1][0] + dis(a[i].x, a[i].y, a1[i - 1].x, a1[i - 1].y);
      }
      if (f[i - 1][1] != -1) {
        if (f[i][0] == -1 ||
            f[i][0] > f[i - 1][1] + dis(a[i].x, a[i].y, a[i - 1].x, a[i - 1].y))
          f[i][0] = f[i - 1][1] + dis(a[i].x, a[i].y, a[i - 1].x, a[i - 1].y);
      }
    }
    if (a[i].y != -1) {
      if (f[i - 1][0] != -1) {
        if (f[i][1] == -1 ||
            f[i][1] >
                f[i - 1][0] + dis(a1[i].x, a1[i].y, a1[i - 1].x, a1[i - 1].y))
          f[i][1] =
              f[i - 1][0] + dis(a1[i].x, a1[i].y, a1[i - 1].x, a1[i - 1].y);
      }
      if (f[i - 1][1] != -1) {
        if (f[i][1] == -1 ||
            f[i][1] >
                f[i - 1][1] + dis(a1[i].x, a1[i].y, a[i - 1].x, a[i - 1].y))
          f[i][1] = f[i - 1][1] + dis(a1[i].x, a1[i].y, a[i - 1].x, a[i - 1].y);
      }
    }
  }
  long long u;
  if (f[num][0] == -1)
    u = f[num][1];
  else if (f[num][1] == -1)
    u = f[num][0];
  else
    u = min(f[num][0], f[num][1]);
  printf("%lld", ans + u);
}
