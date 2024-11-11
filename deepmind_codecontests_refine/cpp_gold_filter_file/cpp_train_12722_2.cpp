#include <bits/stdc++.h>
using namespace std;
int t, n;
int a[2000010];
int b[2000010], p;
int main() {
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    int tmp;
    for (int i = 1; i <= n; i++) {
      scanf("%d", &tmp);
      a[tmp]++;
    }
    for (int i = 1; i <= n; i++) {
      if (a[i]) {
        b[++p] = a[i];
      }
    }
    sort(b + 1, b + 1 + p);
    int ans = 1e9;
    for (int i = 2; i <= b[1] + 1; i++) {
      tmp = 0;
      for (int j = 1; j <= p; j++) {
        if (b[j] % i == 0) {
          tmp += (b[j] / i);
        } else {
          if (b[j] + 1 + b[j] / i >= (b[j] / i + 1) * i) {
            tmp += (b[j] / i + 1);
          } else {
            tmp = 1e9;
            break;
          }
        }
      }
      ans = min(ans, tmp);
    }
    printf("%d\n", ans);
    for (int i = 1; i <= n; i++) {
      a[i] = 0;
    }
    p = 0;
  }
  return 0;
}
