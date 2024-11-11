#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 7;
struct node {
  int x, y;
} a[maxn], pre[maxn], now[maxn];
int n, m;
bool cmp(node a, node b) {
  if (a.y == b.y) return a.x < b.x;
  return a.y < b.y;
}
bool check() {
  int cnt = 1;
  pre[0].x = 1, pre[0].y = 1;
  for (int i = 0; i < m; i++) {
    if (a[i].y != a[i - 1].y + 1) {
      cnt = 1;
      pre[0].y = n;
    }
    int k;
    for (k = i + 1; a[k].y == a[i].y; k++)
      ;
    k--;
    int num = 0;
    int res = 0;
    for (int j = i; j <= k; j++) {
      if (a[j].x > res + 1) {
        now[num].x = res + 1;
        now[num].y = a[j].x - 1;
        num++;
      }
      res = a[j].x;
    }
    if (n > res) {
      now[num].x = res + 1;
      now[num].y = n;
      num++;
    }
    int t = 0;
    for (int j = 0; j < cnt; j++) {
      while (now[t].x <= pre[j].y && t < num) {
        if (now[t].y >= pre[j].x) {
          now[t].x = max(now[t].x, pre[j].x);
        } else {
          now[t].x = -1;
          now[t].y = -1;
        }
        t++;
      }
      if (t > num) break;
    }
    cnt = 0;
    for (int j = 0; j < t; j++) {
      if (now[j].x != -1 && now[j].y != -1) {
        pre[cnt].x = now[j].x;
        pre[cnt].y = now[j].y;
        cnt++;
      }
    }
    if (cnt == 0) return false;
    i = k;
  }
  if (a[m - 1].y != n) return true;
  if (pre[cnt - 1].y == n) return true;
  return false;
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < m; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    a[i].x = x;
    a[i].y = y;
  }
  sort(a, a + m, cmp);
  if (check())
    printf("%d\n", 2 * n - 2);
  else
    puts("-1");
  return 0;
}
