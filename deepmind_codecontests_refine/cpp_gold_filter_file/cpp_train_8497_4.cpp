#include <bits/stdc++.h>
using namespace std;
const int maxn = 200000 + 10;
int a[maxn], ans, now[maxn];
int vis[maxn], k[maxn];
int main() {
  int n, flag = 1, xxx = 0, m, sum = 0;
  scanf("%d", &n);
  n++;
  scanf("%d", &a[1]);
  sum = a[1];
  for (int i = 2; i <= n; i++) {
    scanf("%d", &a[i]);
    if (xxx == 0) sum += a[i];
    if (a[i - 1] > 1 && a[i] > 1) {
      flag = 0;
      if (xxx == 0) xxx = i;
    }
  }
  if (flag) {
    printf("perfect\n");
    return 0;
  }
  printf("ambiguous\n");
  now[1] = 0;
  ans = 2;
  k[1] = 1;
  memset(vis, 0, sizeof vis);
  for (int i = 2; i <= n; i++) {
    m = k[i - 1];
    k[i] = ans;
    for (int j = 1; j <= a[i]; j++) {
      now[ans] = m;
      ans++;
    }
  }
  for (int i = 1; i < ans; i++) {
    printf("%d%c", now[i], i == ans - 1 ? '\n' : ' ');
  }
  now[sum] = k[xxx - 1] + 1;
  for (int i = 1; i < ans; i++) {
    printf("%d%c", now[i], i == ans - 1 ? '\n' : ' ');
  }
}
