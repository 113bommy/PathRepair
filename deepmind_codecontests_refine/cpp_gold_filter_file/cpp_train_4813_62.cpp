#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1);
void add(long long int &a, long long int b) {
  a += b;
  if (a >= 1000000007) a %= 1000000007;
}
void subtract(long long int &a, long long int b) {
  a -= (b - 1000000007);
  if (a >= 1000000007) a -= 1000000007;
}
long long int multiply(long long int a, long long int b) {
  long long int res = a;
  res *= b;
  if (res >= 1000000007) res %= 1000000007;
  return res;
}
void solve() {
  long long int a, b, c;
  cin >> a >> b >> c;
  long long int x, y, z;
  long long int ans = INT_MAX;
  for (long long int i = 1; i <= 20000; i++) {
    long long int val = i;
    long long int inc1 = INT_MAX, inc2 = INT_MAX;
    for (long long int j = 1; j * j <= val; j++) {
      if (val % j == 0) {
        long long int val1 = j;
        inc1 = min(inc1, abs(a - val1));
        val1 = val / j;
        inc1 = min(inc1, abs(a - val1));
      }
    }
    if (c <= val) {
      inc2 = val - c;
    } else {
      long long int val1 = c % val;
      inc2 = min({inc2, abs(val1 - val), val1});
    }
    if (inc1 + inc2 + abs(b - val) < ans) {
      ans = inc1 + inc2 + abs(b - val);
      if (val % (a + inc1) == 0) {
        x = a + inc1;
      } else {
        x = a - inc1;
      }
      if ((c + inc2) % val == 0)
        z = c + inc2;
      else
        z = c - inc2;
      y = val;
    }
  }
  cout << ans << "\n";
  cout << x << " " << y << " " << z << "\n";
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
