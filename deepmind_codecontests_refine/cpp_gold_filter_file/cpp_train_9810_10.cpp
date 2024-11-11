#include <bits/stdc++.h>
using namespace std;
string modify(string second, long long int n, long long int k) {
  string pre = second.substr(k - 1, n - k + 1);
  string suf = second.substr(0, k - 1);
  if (n % 2 == k % 2) {
    reverse(suf.begin(), suf.end());
  }
  return pre + suf;
}
int32_t main() {
  long long int t;
  cin >> t;
  while (t--) {
    long long int n, k;
    string second, best;
    cin >> n >> second;
    best = modify(second, n, 1);
    k = 1;
    for (long long int i = 2; i <= n; i++) {
      string tmp = modify(second, n, i);
      if (tmp < best) {
        best = tmp;
        k = i;
      }
    }
    cout << best << '\n' << k << '\n';
  }
}
