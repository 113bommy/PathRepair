#include <bits/stdc++.h>
using namespace std;
const int MAXN = 3e5 + 5;
int n;
long long k, f[MAXN];
int main() {
  int t;
  scanf("%d", &t);
  f[1] = 1;
  for (int i = 2; i <= 31; i++) {
    f[i] = 4ll * f[i - 1] + 1ll;
  }
  while (t--) {
    scanf("%d%I64d", &n, &k);
    if (n > 31) {
      printf("YES %d\n", n - 1);
    } else {
      int ans = -1;
      for (int i = 31; i >= 0; i--) {
        long long temp = 0, p = 2ll;
        for (int j = 1; j <= n - i; j++) {
          temp += p - 1;
          p *= 2ll;
        }
        if (temp > k) continue;
        if (f[n] - f[i] * (p - 1) < k) continue;
        ans = i;
        break;
      }
      if (ans == -1)
        cout << "NO" << endl;
      else {
        cout << "YES"
             << " " << ans << endl;
      }
    }
  }
  return 0;
}
