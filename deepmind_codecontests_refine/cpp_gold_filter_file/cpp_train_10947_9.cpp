#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  int q;
  cin >> q;
  while (q--) {
    ll n;
    cin >> n;
    int cnt5 = 0;
    while (n % 5 == 0) {
      cnt5++;
      n /= 5;
    }
    int cnt3 = 0;
    while (n % 3 == 0) {
      cnt3++;
      n /= 3;
    }
    int cnt2 = 0;
    while (n % 2 == 0) {
      cnt2++;
      n /= 2;
    }
    if (n != 1) {
      cout << -1 << endl;
    } else {
      cout << cnt2 + 2 * cnt3 + 3 * cnt5 << endl;
    }
  }
  return 0;
}
