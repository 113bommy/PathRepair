#include <bits/stdc++.h>
int n, m;
bool vis[300010];
int main() {
  scanf("%d", &n);
  m = n;
  printf("1");
  for (int i = 0, p; i < n; i++) {
    scanf("%d", &p);
    vis[p] = 1;
    while (m && vis[m]) m--;
    printf(" %d", i + 1 - n + m + 1);
  }
}
