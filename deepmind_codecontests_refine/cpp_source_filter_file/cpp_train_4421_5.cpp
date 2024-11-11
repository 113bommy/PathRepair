#include <bits/stdc++.h>
using namespace std;
int a[105];
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", a + i);
  }
  int ans = 0;
  int st = 0;
  for (int i = 1; i <= n; i++) {
    if (a[i]) {
      ans++;
      st = i;
      break;
    }
  }
  for (int i = st; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) {
      if (a[j]) {
        ans += min(2, j - i);
        i = j;
        break;
      }
    }
  }
  printf("%d\n", ans);
  return 0;
}
