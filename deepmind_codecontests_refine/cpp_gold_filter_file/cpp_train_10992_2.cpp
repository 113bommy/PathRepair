#include <bits/stdc++.h>
using namespace std;
signed main() {
  long long ans = 0, min1 = 10000, r, d, a = 0, pos, b = 0, i, n, k = 0, m = 0,
            t, tot = 0, c = 0, s = 0, t1, c1 = 0, k4 = 0, c2 = 0, j = 0, k1 = 0,
            k2, k3;
  char ch, ch1[2000];
  string s1;
  ios::sync_with_stdio(0);
  pair<long long, long long> p1;
  cin.tie(0);
  cin >> s1;
  n = s1.length();
  for (long long i = n - 1; i >= 0; i--) {
    if (s1[i] == 'b')
      b++;
    else if (b) {
      ans += b;
      b *= 2;
      ans %= 1000000007;
      b %= 1000000007;
    }
  }
  cout << ans;
}
