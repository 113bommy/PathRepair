#include <bits/stdc++.h>
using namespace std;
int a[111111], b[111111];
int main() {
  int n, cur = 0, ans = 0;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
  }
  for (int i = 1; i <= n; i++) {
    cur = min(cur, a[i] - i);
    b[i] = i + cur;
  }
  cur = n + 1;
  for (int i = n; i > 0; i--) {
    cur = min(cur, a[i] + i);
    b[i] = min(b[i], cur - i);
  }
  for (int i = 0; i < n; i++) {
    ans = max(ans, b[i]);
  }
  printf("%d\n", ans);
  cin.get();
  cin.get();
  return 0;
}
