#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007ll;
string s;
long long n;
bool check(long long l, long long r) {
  for (long long i = l; i <= r; i++) {
    for (long long k = 1; i + 2 * k <= r; k++) {
      if (s[i] == s[i + k] and s[i] == s[i + 2 * k]) return 0;
    }
  }
  return 1;
}
long long ans;
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> s;
  n = s.size();
  s = "$" + s;
  for (long long i = 1; i <= n; i++) {
    for (long long j = i + 1; j - i < 100 and j <= n; j++)
      if (check(i, j)) {
        ans--;
      }
  }
  ans += (n * n - n) / 2;
  cout << ans;
  return 0;
}
