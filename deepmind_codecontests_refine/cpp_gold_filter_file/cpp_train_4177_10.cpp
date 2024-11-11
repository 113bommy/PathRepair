#include <bits/stdc++.h>
using namespace std;
long long v[300005], n, p[300005], s[300005];
int nr1(long long x) {
  int ans = 0;
  while (x) {
    if (x % 2) ans++;
    x /= 2;
  }
  return ans;
}
int main() {
  ios::sync_with_stdio(false);
  cin >> n;
  p[0] = 1;
  for (int i = 1; i <= n; i++) {
    cin >> v[i];
    v[i] = nr1(v[i]);
    s[i] = s[i - 1] + v[i];
    p[i] = p[i - 1] + (s[i] % 2 == 0);
  }
  long long ans = 0;
  for (int i = 2; i <= n; i++) {
    long long j = i, sum = v[i], mx = v[i];
    while (j > 1 && sum < 150) {
      j--;
      mx = max(mx, v[j]);
      sum += v[j];
      if (sum >= 2 * mx && sum % 2 == 0) ans++;
    }
    if (j > 1) {
      if (s[i] % 2 == 0)
        ans += p[j - 2];
      else
        ans += j - (p[j - 2]) - 1;
    }
  }
  cout << ans << '\n';
  return 0;
}
