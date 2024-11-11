#include <bits/stdc++.h>
using namespace std;
int s[200];
int main() {
  long long n, k, ans = 0, a = 0;
  cin >> n >> k;
  for (int i = 0; i < n; i++) cin >> a, s[a % k]++;
  for (int i = 1; i < k / 2 + k % 2; i++) ans += min(s[i], s[k - i]) * 2;
  if (k % 2 == 0) ans += s[k / 2];
  ans += s[0] / 2 * 2;
  cout << ans << endl;
}
