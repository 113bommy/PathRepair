#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    int sum = 0;
    if ((n % 2 == 0 && m % 2 == 0) || (n % 2 == 0 && m % 2 != 0)) {
      sum = m * (n / 2);
      cout << sum << endl;
    } else if (n % 2 != 0 && m % 2 == 0) {
      sum = m * (n / 2) + m / 2 + 1;
      cout << sum << endl;
    } else if (n % 2 != 0 && m % 2 != 0) {
      sum = ((m - 1) * (n / 2)) + (n / 2) + (m / 2) + 1;
      cout << sum << endl;
    }
  }
  return 0;
}
