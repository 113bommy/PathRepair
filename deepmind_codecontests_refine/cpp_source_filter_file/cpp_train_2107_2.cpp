#include <bits/stdc++.h>
const long long int M = 998244353;
const long long int mod1 = 1e9 + 7;
const long long int inf = 1e18 + 5;
using namespace std;
long long int power(long long int x, long long int y, long long int p) {
  long long int res = 1;
  x = x % p;
  if (x == 0) return 0;
  while (y > 0) {
    if (y & 1) res = (res * x) % p;
    y = y >> 1;
    x = (x * x) % p;
  }
  return res;
}
void solve() {
  long long int n;
  cin >> n;
  long long int a[n];
  vector<long long int> v;
  bool equal = false, sameAdj = false;
  for (long long int i = 0; i < n; i++) {
    cin >> a[i];
    if (i != 0 && a[i] != a[i - 1]) equal = true;
  }
  vector<long long int> ans(n);
  if (!equal) {
    cout << 1 << "\n";
    for (long long int k = 0; k < n; k++) cout << 1 << " ";
    cout << "\n";
  } else if (!n % 2) {
    cout << 2 << "\n";
    for (long long int i = 0; i < n; i++)
      cout << (i % 2 == 1 ? "2" : "1") << " ";
    cout << "\n";
  } else {
    for (long long int i = 0; i < n; i++) {
      if (a[i] == a[(i + 1) % n]) {
        sameAdj = true;
        long long int x = 0;
        for (long long int j = i + 1; j < n; j++) {
          ans[j] = x + 1;
          x ^= 1;
        }
        x = 0;
        for (long long int j = i; j >= 0; j--) {
          ans[j] = x + 1;
          x ^= 1;
        }
        cout << 2 << "\n";
        for (auto k : ans) cout << k << " ";
        cout << "\n";
        break;
      }
    }
    if (!sameAdj) {
      cout << 3 << "\n";
      for (long long int i = 0; i < n - 1; i++)
        cout << (i % 2 == 1 ? "2" : "1") << " ";
      cout << "3\n";
    }
  }
}
signed main() {
  cin.tie(0);
  cout.tie(0);
  ios_base::sync_with_stdio(0);
  ;
  long long int t = 1;
  cin >> t;
  while (t--) solve();
  return 0;
}
