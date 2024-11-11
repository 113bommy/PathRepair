#include <bits/stdc++.h>
using namespace std;
map<long long, long long> en;
long long mon[200003];
map<long long, long long> e;
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  long long tc;
  cin >> tc;
  while (tc--) {
    long long n;
    cin >> n;
    for (long long i = 0; i < n; i++) cin >> mon[i];
    long long m;
    en.clear();
    e.clear();
    cin >> m;
    long long k, kk;
    for (long long i = 0; i < m; i++) {
      cin >> k >> kk;
      en[kk] = max(en[kk], k);
    }
    for (long long i = n; i >= 1; i--) {
      e[i] = max(e[i + 1], en[i]);
    }
    long long ans = 1, tk = 1;
    long long mx = 0;
    for (long long i = 0; i < n; i++) {
      mx = max(mx, mon[i]);
      if (e[tk] < mx) {
        if (tk == 1) {
          ans = -1;
          break;
        }
        mx = 0;
        i--;
        tk = 0;
        ans++;
      }
      tk++;
    }
    cout << ans << '\n';
  }
  return 0;
}
