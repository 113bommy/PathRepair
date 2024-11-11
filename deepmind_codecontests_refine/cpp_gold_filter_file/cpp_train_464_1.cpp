#include <bits/stdc++.h>
using namespace std;
int n, k, ans, f[100005], x, top;
int main() {
  ans = top = 0;
  scanf("%d%d", &n, &k);
  ans = n * 2 - k - 1;
  for (int i = 1; i <= k; i++) {
    scanf("%d", &n);
    for (int j = 1; j <= n; j++) scanf("%d", &f[j]);
    if (f[1] == 1) {
      for (int j = 2; j <= n; j++)
        if (f[j] == j)
          ans -= 2;
        else
          break;
    }
  }
  cout << ans << endl;
  return 0;
}
