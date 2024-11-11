#include <bits/stdc++.h>
using namespace std;
#pragma warning(disable : 4996)
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  vector<int> a(11);
  cout << fixed << setprecision(2);
  for (int i = 0; i < 11; i++) cin >> a[i];
  for (int i = 10; i >= 0; i--) {
    double cur = sqrt(abs(a[i])) + 5 * pow(a[i], 3);
    if (cur > 400) {
      cout << "f(" << a[i] << ") = "
           << "MAGNA NIMIS!\n";
    } else {
      cout << "f(" << a[i] << ") = " << cur << "\n";
    }
  }
}
