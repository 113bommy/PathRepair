#include <bits/stdc++.h>
using namespace std;
const long long N = 1.5e6;
long long pbad[N];
long long n, a, b, t;
long long spent(long long m) {
  return (n - m + 1) * a + (n - m + 1) + b * (pbad[n] - pbad[m - 1]);
}
long long solve(string s) {
  memset(pbad, 0, sizeof pbad);
  s = '0' + s + s;
  for (long long i = 1; i < s.size(); i++)
    pbad[i] = pbad[i - 1] + (s[i] == 'w');
  long long ans = 0;
  for (long long rm = 1; rm <= n; rm++) {
    long long left = t - (rm + pbad[rm] * b + (rm - 1) * a) - (a * (rm - 1));
    if (left < 0) continue;
    ans = max(ans, rm);
    if (rm == n) break;
    long long l = rm, r = n;
    while (r - l > 1) {
      long long m = (l + r) / 2;
      if (spent(m) > left)
        l = m;
      else
        r = m;
    }
    ans = max(ans, rm + n - r + 1);
  }
  return ans;
}
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> a >> b >> t;
  string s;
  cin >> s;
  string t = s;
  long long ans = solve(t);
  reverse(t.begin() + 1, t.end());
  cout << max(ans, solve(t));
}
