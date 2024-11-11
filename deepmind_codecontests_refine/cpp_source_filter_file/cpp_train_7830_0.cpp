#include <bits/stdc++.h>
using namespace std;
const long long N = 1e5 + 10;
int32_t main() {
  ios_base ::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  long long t = 1;
  while (t--) {
    long long n;
    cin >> n;
    string p;
    cin >> p;
    long long a[n + 2];
    a[0] = 0;
    long long parity = 0;
    long long i = 1;
    for (auto x : p) {
      parity += ((x == '(') ? +1 : -1);
      a[i] = parity;
      i++;
    }
    long long ans = 0;
    if (!parity) {
      for (long long i = 0; i < n;) {
        if (a[i] == 0) {
          long long j = i + 1;
          bool cond = false;
          while (j <= n and a[j] != 0) {
            if (a[j] < 0) cond = true;
            j++;
          }
          if (a[j] != 0) {
            cout << -1 << endl;
            return 0;
          }
          if (cond) ans += (j - i);
          i = j + 1;
        } else
          i++;
      }
      cout << ans << endl;
    } else
      cout << -1 << endl;
  }
  return 0;
}
