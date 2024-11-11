#include <bits/stdc++.h>
using namespace std;
long long f[1000010];
long n, tot1, tot2, i, j, ans;
int main() {
  cin >> n;
  ans = 1;
  for (i = 1; i <= n; i++) {
    cin >> j;
    if (j == 1)
      tot1++;
    else
      tot2++;
  }
  for (i = 0; i < tot2; i++) ans = (ans * (n - i)) % 1000000007;
  f[0] = 1;
  f[1] = 1;
  for (i = 2; i <= tot1; i++) {
    f[i] = 1;
    for (j = i - 2; j >= 0; j--) f[i] = (f[i] + f[j] * (j + 1)) % 1000000007;
  }
  ans = (ans * f[tot1]) % 1000000007;
  cout << ans << endl;
  return 0;
}
