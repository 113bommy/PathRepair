#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, ans = 0;
  scanf("%d", &n);
  int minn = 1e9;
  for (int i = 1; i <= n; i++) {
    int t;
    scanf("%d", &t);
    if (t < 0 && ((-t) % 2 == 1)) minn = min(minn, -t);
    if (t > 0) {
      ans += t;
      if (t & 1) minn = min(minn, t);
    }
  }
  if (ans % 2 == 1)
    printf("%d\n", ans);
  else
    printf("%d\n", ans - minn);
  return 0;
}
