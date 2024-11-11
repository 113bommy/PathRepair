#include <bits/stdc++.h>
using namespace std;
const long long maxn = 3000000000;
int main() {
  long long n, k, p, a[1010], b[2020];
  cin >> n >> k >> p;
  for (int i = 0; i < n; i++) scanf("%I64d", &a[i]);
  for (int j = 0; j < k; j++) scanf("%I64d", &b[j]);
  sort(a, a + n);
  sort(b, b + k);
  long long ans = maxn;
  if (n > 1)
    for (int i = 0; i + n <= k; i++) {
      long long temp = 0;
      for (int j = 0; j < n; j++)
        temp = max(temp, abs(p - b[i + j]) + abs(b[i + j] - a[i + j]));
      ans = min(temp, ans);
    }
  else
    for (int i = 0; i < k; i++)
      ans = min(ans, abs(p - b[i]) + abs(b[i] - a[0]));
  cout << ans << endl;
  return 0;
}
