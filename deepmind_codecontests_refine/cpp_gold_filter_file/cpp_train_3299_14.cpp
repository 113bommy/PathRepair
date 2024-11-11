#include <bits/stdc++.h>
using namespace std;
int a[100001];
int main() {
  int n;
  scanf("%d", &n);
  int ans = 1;
  int minn = 0x7f7f7f7f;
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
    minn = min(minn, a[i]);
  }
  for (int i = 1; i <= n; ++i) {
    a[i] -= minn;
  }
  ans = minn % n + 1;
  int k = 1;
  while (1) {
    if (a[ans] <= 0) {
      printf("%d\n", ans);
      return 0;
    }
    if (ans + 1 > n) ans = 0;
    a[ans + 1] -= k;
    k++;
    ans++;
  }
  return 0;
}
