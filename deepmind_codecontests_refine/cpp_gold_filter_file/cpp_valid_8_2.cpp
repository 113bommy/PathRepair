#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t;
  cin >> t;
  while (t--) {
    long long n, c1 = 0, c2 = 0;
    cin >> n;
    c1 = n / 3;
    c2 = (n - c1) / 2;
    if (c1 + (2 * c2) == n)
      cout << c1 << " " << c2 << endl;
    else {
      cout << c1 + 1 << " " << c2 << endl;
    }
  }
  return 0;
}
