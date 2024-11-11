#include <bits/stdc++.h>
using namespace std;
const long long maxn = 8e5 + 5;
const long long mod = 1e9 + 7;
const long double PI = 4 * atan((long double)1);
long long pw(long long a, long long b) {
  return (!b ? 1
             : (b & 1 ? a * pw(a * a % mod, b / 2) % mod
                      : pw(a * a % mod, b / 2) % mod));
}
int n;
int cnt1 = 0, cnt2 = 0;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    if (x > 0) {
      cnt1++;
    } else {
      cnt2++;
    }
  }
  if (cnt1 <= 1 or cnt2 <= 1) {
    cout << "YES";
    return (0);
    ;
  }
  cout << "NO";
  return (0);
}
