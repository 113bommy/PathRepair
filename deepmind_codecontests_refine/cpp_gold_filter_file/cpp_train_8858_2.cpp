#include <bits/stdc++.h>
using namespace std;
int n, a[1010], b[1010];
int x[1010], y[1010], cnt;
int c[1010];
bool vis[1010] = {0};
int main() {
  scanf("%d", &n);
  for (int i = 1; i < n; i++) {
    scanf("%d%d", &a[i], &b[i]);
    vis[a[i]] = vis[b[i]] = 1;
    c[a[i]]++;
    c[b[i]]++;
  }
  for (int i = 1; i < n; i++) {
    if (c[i] == 0) continue;
    if (c[i] == 1) {
      x[++cnt] = i;
      y[cnt] = n;
      continue;
    }
    int tmp = 0;
    int la = i;
    for (int j = 1; j < i; j++) {
      if (!vis[j]) {
        x[++cnt] = la;
        y[cnt] = j;
        tmp++;
        vis[j] = 1;
        la = j;
        if (tmp + 1 == c[i]) break;
      }
    }
    if (tmp + 1 != c[i]) {
      printf("NO");
      return 0;
    }
    x[++cnt] = la;
    y[cnt] = n;
  }
  printf("YES\n");
  for (int i = 1; i < n; i++) {
    printf("%d %d\n", x[i], y[i]);
  }
  return 0;
}
