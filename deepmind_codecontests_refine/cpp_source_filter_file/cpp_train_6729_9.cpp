#include <bits/stdc++.h>
using namespace std;
int vis[100010];
int main() {
  int n, bit = 1;
  scanf("%d", &n);
  while ((bit << 1) < n) {
    bit <<= 1;
  }
  if (n & 1) {
    puts("NO");
  } else {
    puts("YES");
    int bit1 = bit;
    for (int i = n; i >= 1; i--) {
      if (bit1 > i) {
        bit1 >>= 1;
      }
      if (!vis[i]) {
        int now = bit1 * 2 - i - 1;
        vis[i] = now;
        vis[now] = i;
      }
    }
    for (int i = 1; i <= n; i++) {
      printf("%d ", vis[i]);
    }
    puts("");
  }
  if (n == bit || n < 6) {
    puts("NO");
  } else {
    puts("YES");
    if (n == 6) {
      puts("3 6 2 5 1 4");
    } else {
      printf("7 3 6 5 1 2 4");
      for (int i = 8; i <= n;) {
        int j = min(i << 1, n + 1);
        for (int k = i; k < j - 1; k++) {
          printf("%d ", k + 1);
        }
        printf("%d ", i);
        i = j;
      }
    }
  }
  return 0;
}
