#include <bits/stdc++.h>
using namespace std;
int a[100005];
int main() {
  int T, n;
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &n);
    int ans = 0;
    for (int i = 0; i < n; i++) {
      scanf("%d", &a[i]);
      if (i && a[i] <= a[i - 1]) {
        ans = 1;
      }
    }
    if (n % 2 == 0) ans = 1;
    if (ans)
      printf("YES\n");
    else
      printf("NO\n");
  }
  return 0;
}
