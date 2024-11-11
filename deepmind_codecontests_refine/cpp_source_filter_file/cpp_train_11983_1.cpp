#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
int n, a[N], top;
int q[N], vis[N];
pair<int, int> ans[N];
void insert(int x, int y) {
  ans[++top] = (pair<int, int>(x - 2 * y, y));
  a[x] ^= 1;
  a[x - y] ^= 1;
  a[x - y - y] ^= 1;
}
void check(int n) {
  int st = 0, h = 0, t = 1;
  memset(vis, -1, sizeof(vis));
  for (int i = (int)(1); i <= (int)(n); i++) st |= a[i] << (i - 1);
  q[1] = st;
  vis[st] = 0;
  while (h != t) {
    int x = q[++h];
    for (int v1 = (int)(0); v1 <= (int)(n); v1++)
      for (int v2 = (int)(1); v2 <= (int)(n); v2++)
        if (v1 + 2 * v2 < n) {
          int y = x ^ (1 << v1) ^ (1 << (v1 + v2)) ^ (1 << (v1 + v2 + v2));
          if (vis[y] == -1) vis[y] = v1 * 1000 + v2, q[++t] = y;
        }
  }
  if (vis[0] == -1)
    puts("NO");
  else {
    for (int i = 0; i != st;) {
      int x = vis[i] / 1000, y = vis[i] % 1000;
      ans[++top] = pair<int, int>(x + 1, y);
      i ^= (1 << x) ^ (1 << (x + y)) ^ (1 << (x + y + y));
    }
    printf("YES\n%d\n", top);
    for (int i = (int)(1); i <= (int)(top); i++)
      printf("%d %d %d\n", ans[i].first, ans[i].first + ans[i].second,
             ans[i].first + 2 * ans[i].second);
  }
}
int main() {
  scanf("%d", &n);
  for (int i = (int)(1); i <= (int)(n); i++) scanf("%d", &a[i]);
  int m = n;
  for (;;) {
    for (; m > 10 && a[m] == 0; --m)
      ;
    if (m <= 10) break;
    if (a[m - 1] == 0 && a[m - 2] == 0)
      insert(m, 3);
    else if (a[m - 1] == 0 && a[m - 2] == 1)
      insert(m, 2);
    else if (a[m - 1] == 1 && a[m - 2] == 1)
      insert(m, 1);
    else if (a[m - 3] == 1 && a[m - 4] == 1 && a[m - 5] == 1)
      insert(m, 4), insert(m - 1, 2);
    else {
      if (a[m - 3])
        insert(m, 3);
      else if (a[m - 4])
        insert(m, 4);
      else if (a[m - 5])
        insert(m, 5);
      else
        insert(m, 6);
      if (a[m - 3])
        insert(m - 1, 2);
      else if (a[m - 4])
        insert(m - 1, 3);
      else if (a[m - 5])
        insert(m - 1, 4);
      else
        insert(m - 1, 5);
    }
  }
  check(min(n, 12));
}
