#include <bits/stdc++.h>
using namespace std;
int f[3000];
int t[3000];
int n;
int main() {
  int x;
  scanf("%d %d", &n, &x);
  f[0] = 0;
  t[0] = x;
  int ans = x;
  for (int i = 1; i <= n; i++) {
    int a;
    scanf("%d", &a);
    if (x / a <= f[i - 1]) {
      if (x / a == f[i - 1] && t[i - 1] < x % a)
        t[i] = x % a;
      else
        t[i] = t[i - 1];
      f[i] = f[i - 1];
    } else {
      t[i] = x % a;
      f[i] = x / a;
    }
    ans = max(ans, f[i - 1] * a + t[i - 1]);
  }
  cout << ans << endl;
  return 0;
}
