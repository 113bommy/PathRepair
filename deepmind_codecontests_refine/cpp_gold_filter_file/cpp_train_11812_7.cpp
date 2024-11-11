#include <bits/stdc++.h>
using namespace std;
int n, m, k;
long long a[300010], sum[300010];
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  sort(a + 1, a + n + 1);
  for (int i = 1; i <= n; i++) sum[i] = sum[i - 1] + a[i];
  long long ans = 0;
  int l = 1, r = n;
  ans = sum[r] - sum[l - 1];
  while (l < r) {
    ans += sum[r] - sum[l - 1];
    l++;
  }
  cout << ans << endl;
  return 0;
}
