#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    if (n == 1)
      cout << "1"
           << "\n";
    else if (n == 3)
      cout << "2"
           << "\n";
    else if (n % 2 == 0)
      cout << n / 2 << "\n";
    else if (n % 2 == 1)
      cout << (n - 1) / 2 << "\n";
  }
}
