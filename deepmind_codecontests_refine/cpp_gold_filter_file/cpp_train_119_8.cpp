#include <bits/stdc++.h>
using namespace std;
string s[120001];
long long p[181], n, i, z, sum, ans;
long long get(long long a, long long b, long long nom) {
  if (nom == 1) {
    if (a <= b) return a * 2 - 1;
    return a + b - 1;
  } else {
    if (a >= b) return b * 2 - 2;
    return a + b - 1;
  }
}
long long mod(long long a) { return a % 998244353; }
long long st(long long a, long long b) {
  if (b == 0) return 1;
  long long c = st(a, b / 2);
  if (b % 2 != 0)
    return mod(mod(a * c) * c);
  else
    return mod(c * c);
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (i = 1; i <= n; i++) cin >> s[i];
  for (z = 1; z <= 10; z++) {
    sum = 0;
    for (i = 1; i <= n; i++)
      if (s[i].size() >= z) sum += s[i][s[i].size() - z] - 48;
    for (i = 1; i <= n; i++) {
      p[get(z, s[i].size(), 1)] += sum;
      p[get(s[i].size(), z, 2)] += sum;
    }
  }
  for (i = 0; i <= 19; i++) ans = mod(ans + mod(p[i]) * st(10, i));
  cout << ans << '\n';
  return 0;
}
