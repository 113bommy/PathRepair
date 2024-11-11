#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int c, sum;
    cin >> c >> sum;
    if (c >= sum) {
      cout << sum << '\n';
      continue;
    }
    cout << ((sum / c) * (sum / c) * (c - (sum % c)) +
             (sum / c + 1) * (sum / c + 1) * (sum % c))
         << '\n';
  }
  return 0;
}
