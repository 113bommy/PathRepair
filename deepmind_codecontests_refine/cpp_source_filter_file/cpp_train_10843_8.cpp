#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long a, b, m;
  cin >> a >> b >> m;
  for (long long i = 0; i < 50; i++) {
    long long k = ((long long)1 << ((max((long long)0, i - 1))));
    if (!i) {
      if (a == b) {
        cout << 1 << " " << a << '\n';
        return;
      }
    } else {
      if (b >= k * (a + 1) && b <= k * (a + m)) {
        vector<long long> r(i + 1);
        r[0] = 0;
        b -= k * (a + 1);
        for (long long j = 1; j <= i; j++) {
          long long t = (long long)1 << max((long long)0, i - j - 1);
          long long p = min(b / t, m - 1);
          b -= t * p;
          r[j] = p + 1;
        }
        cout << i + 1 << " ";
        long long cur = 0;
        r[0] = a;
        for (long long j = 0; j <= i; j++) {
          cout << cur + r[j] << " ";
          cur += cur + r[j];
        }
        cout << '\n';
        return;
      }
    }
    if (b < k) {
      break;
    }
  }
  cout << -1 << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int tc;
  tc = 1;
  cin >> tc;
  for (int i = 1; i <= tc; i++) {
    solve();
  }
  return 0;
}
