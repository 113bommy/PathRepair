#include <bits/stdc++.h>
using namespace std;
int n;
int a[101];
int vis[101];
int main() {
  scanf("%d", &n);
  int sum = 0;
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    sum += a[i];
  }
  int ave = sum / n * 2;
  if (n == 2)
    printf("1 2\n");
  else {
    for (int i = 1; i <= n; i++) {
      for (int j = i + 1; j <= n; j++) {
        if (!vis[i] && !vis[j] && ((a[i] + a[j]) == ave)) {
          printf("%d %d\n", i, j);
          vis[j] = 1;
          break;
        }
      }
      vis[i] = 1;
    }
  }
  return 0;
}
