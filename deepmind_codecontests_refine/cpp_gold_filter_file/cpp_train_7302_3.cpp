#include <bits/stdc++.h>
using namespace std;
long long ans, sum, n, v[300005], m[300005], a[300005];
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> v[i] >> m[i], sum += v[i];
  for (int i = 1; i <= n; i++)
    for (int j = 0; j < 62; j++)
      if ((m[i] >> j) & 1) a[i] = j;
  if (sum < 0)
    for (int i = 1; i <= n; i++) v[i] = -v[i];
  for (int i = 0; i < 62; i++) {
    sum = 0;
    for (int j = 1; j <= n; j++)
      if (a[j] == i) sum += v[j];
    if (sum > 0) {
      ans |= (1ll << i);
      for (int j = 1; j <= n; j++)
        if ((m[j] >> i) & 1) v[j] = -v[j];
    }
  }
  cout << ans;
  return 0;
}
