#include <bits/stdc++.h>
using namespace std;
const int maxn = 5005;
int a[maxn];
int ans[maxn];
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  if (m == 0) {
    int x = 1;
    for (int i = 1; i <= n; i++) {
      printf("%d ", x);
      x += 2;
    }
    printf("\n");
    return 0;
  }
  a[1] = 0;
  for (int i = 2; i <= n; i++) {
    a[i] = a[i - 1] + (i - 1) / 2;
  }
  if (m > a[n]) {
    printf("-1\n");
    return 0;
  }
  int k;
  for (int i = 1; i <= n; i++) {
    if (m > a[i]) {
      continue;
    } else {
      k = i;
      break;
    }
  }
  int f = 0;
  if (a[k] > m) {
    k--;
    f = 1;
  }
  for (int i = 1; i <= k; i++) {
    ans[i] = i;
  }
  int x = k / 2, y = k;
  if (f) {
    y++;
    while (a[k] + x > m) {
      x--;
      y += 2;
    }
    k++;
    ans[k] = y;
  }
  int t = y, s = y;
  t++;
  for (int i = k + 1; i <= n; i++) {
    s += t;
    ans[i] = s;
  }
  for (int i = 1; i <= n; i++) {
    printf("%d ", ans[i]);
  }
}
