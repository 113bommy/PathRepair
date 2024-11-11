#include <bits/stdc++.h>
using namespace std;
long long ans, n, a[50005], sum[50005];
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i], sum[i] = a[i] + sum[i - 1];
  for (int i = 1; i <= n; i++)
    for (int j = i; j <= n; j++)
      if (sum[j] - sum[i - 1] >= 100 * (j - i + 1))
        ans = max(ans, (long long)j - i + 1);
  cout << ans << endl;
}
