#include <bits/stdc++.h>
using namespace std;
const int N = 1005;
int n, cnt[N], vis[N], sum;
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n - 1; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    if (y != n) {
      printf("NO");
      return 0;
    }
    cnt[x]++;
  }
  for (int i = 1; i <= n - 1; i++) {
    sum += cnt[i];
    if (sum > i) {
      printf("NO");
      return 0;
    }
  }
  printf("YES\n");
  for (int i = 1; i <= n - 1; i++) {
    if (vis[i] || !cnt[i]) continue;
    int k = cnt[i], pos = i, tmp = i;
    while (k) {
      if (k == 1) {
        printf("%d %d\n", tmp, n);
        k--;
        break;
      }
      pos--;
      if (vis[pos] || cnt[pos]) continue;
      printf("%d %d\n", tmp, pos);
      tmp = pos;
      k--, vis[pos] = 1;
    }
  }
}
