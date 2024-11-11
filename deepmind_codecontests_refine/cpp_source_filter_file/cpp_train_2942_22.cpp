#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  int t;
  cin >> t;
  while (t--) {
    ll n;
    cin >> n;
    if (n == 1 || n == 2) {
      cout << 1 << endl;
      continue;
    }
    cout << ceil(n / 2.0) << endl;
  }
  return 0;
}
