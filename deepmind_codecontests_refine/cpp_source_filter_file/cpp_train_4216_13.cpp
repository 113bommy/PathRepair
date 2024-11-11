#include <bits/stdc++.h>
using namespace std;
const long long maxn = 1000000 + 10;
long long n, m, po[maxn], h[maxn], hr[maxn], x[maxn], ans, sum, t,
    base = 31, mod = 1000000000 + 7;
string s;
bool ok(long long x) {
  if (x <= 0) return true;
  return (h[x - 1] == hr[t - x]);
}
int main() {
  cin >> n >> m;
  cin >> s;
  t = s.size();
  po[0] = 1;
  for (long long i = 0; i < maxn; i++) po[i] = (po[i - 1] * base) % mod;
  h[0] = s[0] - 'a' + 1;
  for (long long i = 1; i < t; i++)
    h[i] = (h[i - 1] * base + s[i] - 'a' + 1) % mod;
  hr[t - 1] = s[t - 1] - 'a' + 1;
  for (long long i = t - 2; i >= 0; i--)
    hr[i] = (po[t - 1 - i] * (s[i] - 'a' + 1) + hr[i + 1]) % mod;
  for (long long i = 0; i < m; i++) {
    cin >> x[i];
    long long ted = t;
    if (i > 0) {
      if (ok(t - x[i] + x[i - 1]))
        ted = min(x[i] - x[i - 1], t);
      else {
        cout << 0 << endl;
        return 0;
      }
    }
    sum += ted;
  }
  ans = 1;
  for (long long i = 0; i < n - sum; i++) (ans *= 26) %= mod;
  cout << ans << endl;
  return 0;
}
