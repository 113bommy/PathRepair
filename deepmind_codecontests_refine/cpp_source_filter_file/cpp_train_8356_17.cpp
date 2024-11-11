#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int t;
  t = 1;
  cin >> t;
  while (t-- > 0) {
    long long int n;
    cin >> n;
    if (n == 1 && n == 2 && n == 4) {
      cout << "-1";
      cout << "\n";
      continue;
    }
    if (!(n % 3))
      cout << n / 3 << " "
           << "0"
           << " "
           << "0";
    if (n % 3 == 1)
      cout << (n - 7) / 3 << " "
           << "1"
           << " "
           << "0";
    if (n % 3 == 2)
      cout << (n - 5) / 3 << " "
           << "1"
           << " "
           << "0";
    cout << "\n";
  }
}
