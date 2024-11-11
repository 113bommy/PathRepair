#include <bits/stdc++.h>
using namespace std;
int vis[100007];
int main() {
  int n, i, k, p;
  scanf("%d", &n);
  if (n & 1)
    printf("NO\n");
  else {
    printf("YES\n");
    for (i = n; i >= 1; i--) {
      if (vis[i]) continue;
      k = 30;
      while ((1 << k) > i) k--;
      k++;
      k = (1 << k) - 1;
      k = ~k;
      k += i;
      k = ~k;
      vis[k] = i;
      vis[i] = k;
    }
    for (i = 1; i <= n; i++) printf("%d ", vis[i]);
    cout << endl;
  }
  if (n == 6)
    printf("YES\n3 6 2 5 1 4\n");
  else if ((n < 7) || ((n & (n - 1)) == 0))
    printf("NO\n");
  else {
    printf("YES\n");
    printf("3 6 1 5 4 7 2 ");
    p = 8;
    while (p < n) {
      for (i = p; i < min(p << 1, n); i++) {
        printf("%d ", i + 1);
      }
      printf("%d ", p);
      p <<= 1;
    }
    cout << endl;
  }
  return 0;
}
