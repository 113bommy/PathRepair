#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
int main() {
  int t;
  cin >> t;
  while (t--) {
    ll n;
    cin >> n;
    if (n == 1)
      cout << "0" << endl;
    else {
      int ans = 0;
      while (n != 1 && (n % 6 == 0 || (n * 2) % 6 == 0)) {
        if (n % 6 == 0) {
          n = n / 6;
          ans++;
        } else {
          n = n * 2;
          ans++;
        }
      }
      if (n == 1)
        cout << ans << endl;
      else
        cout << "-1" << endl;
    }
  }
  return 0;
}
