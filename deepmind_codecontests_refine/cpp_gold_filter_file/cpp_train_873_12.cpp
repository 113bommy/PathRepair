#include <bits/stdc++.h>
using namespace std;
int arr, vis[10];
int main() {
  int n, k, res = 0;
  scanf("%d%d", &n, &k);
  for (int i = 0; i < n; i++) {
    scanf("%d", &arr);
    memset(vis, 0, sizeof(vis));
    while (arr) {
      vis[arr % 10] = 1;
      arr /= 10;
    }
    int flag = 1;
    for (int i = 0; i < 10; i++) {
      if (i <= k && !vis[i]) flag = 0;
    }
    if (flag) res++;
  }
  printf("%d\n", res);
  return 0;
}
