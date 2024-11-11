#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int t;
  cin >> t;
  while (t--) {
    long long int r, g, b, w, ans = 0, ans1 = 0;
    cin >> r;
    if (r == 0) ans++;
    if (r % 2 == 1) ans1++;
    cin >> g;
    if (g == 0) ans++;
    if (g % 2 == 1) ans1++;
    cin >> b;
    if (b % 2 == 1) ans1++;
    if (b == 0) ans++;
    cin >> w;
    if (w % 2 == 1) ans1++;
    if (ans > 0) {
      if (ans1 > 0)
        cout << "No" << endl;
      else
        cout << "Yes" << endl;
    } else {
      if (ans1 == 2)
        cout << "No" << endl;
      else
        cout << "Yes" << endl;
    }
  }
}
