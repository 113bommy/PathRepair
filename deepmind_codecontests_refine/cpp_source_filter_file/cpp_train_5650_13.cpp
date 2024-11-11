#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long sum = 0;
  long long n;
  cin >> n;
  long long maxl = 0;
  while (n--) {
    long long x;
    cin >> x;
    sum += x;
    maxl = max(maxl, x);
  }
  if (maxl > sum - maxl || sum % 2)
    cout << "T" << endl;
  else
    cout << "HT" << endl;
}
signed main() {
  long long t;
  cin >> t;
  while (t--) {
    solve();
  }
}
