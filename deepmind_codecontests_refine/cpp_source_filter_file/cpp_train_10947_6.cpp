#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int cnt = 0, cnt1 = 0, cnt2 = 0;
    while (n % 2 == 0) {
      cnt++;
      n = n / 2;
    }
    while (n % 3 == 0) {
      cnt1++;
      n = n / 3;
    }
    while (n % 5 == 0) {
      cnt2++;
      n = n / 5;
    }
    if (n != 1)
      cout << "-1" << endl;
    else
      cout << cnt + cnt1 * 2 + cnt2 * 3 << endl;
  }
}
