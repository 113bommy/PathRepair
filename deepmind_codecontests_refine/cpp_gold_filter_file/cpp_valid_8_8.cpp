#include <bits/stdc++.h>
using namespace std;
int main() {
  long t, n;
  int c1, c2;
  cin >> t;
  while (t--) {
    cin >> n;
    if (n % 3 == 0)
      c1 = c2 = n / 3;
    else if (n % 3 == 1) {
      c1 = n / 3 + 1;
      c2 = n / 3;
    } else {
      c1 = n / 3;
      c2 = n / 3 + 1;
    }
    cout << c1 << " " << c2 << "\n";
  }
}
