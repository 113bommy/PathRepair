#include <bits/stdc++.h>
using namespace std;
const long long MAX = (long long)1e6 + 100;
long long inf = (long long)1e12;
long long mod = (long long)998244353;
long long n, k;
void solve() {
  long long uk1 = 0, uk2 = (long long)1e9 + 1;
  cin >> n;
  long long mb = 0;
  cout << 0 << " " << 0 << endl;
  string s;
  cin >> s;
  if (s == "black") mb = 1;
  for (int i = 0; i < n - 1; i++) {
    long long mid = (uk2 + uk1) / 2;
    cout << 0 << " " << mid << endl;
    string tp;
    cin >> tp;
    if (tp == "black") {
      if (mb)
        uk1 = mid;
      else
        uk2 = mid;
    } else {
      if (mb)
        uk2 = mid;
      else
        uk1 = mid;
    }
  }
  cout << 0 << " " << uk1 + 1 << " " << 1 << " " << uk1 + 1 << endl;
}
int main() {
  mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
  long long q;
  ios::sync_with_stdio(0);
  q = 1;
  while (q--) solve();
  return 0;
}
