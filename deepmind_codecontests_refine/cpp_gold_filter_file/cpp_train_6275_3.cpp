#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    if (n == 1)
      cout << 0 << "\n";
    else {
      int a = sqrt(n);
      int b = (n - pow(a, 2)) / a;
      int c = (int)(n - pow(a, 2)) % a;
      int nmove = 2 * a + b - 1;
      if (c != 0)
        cout << nmove << "\n";
      else
        cout << nmove - 1 << "\n";
    }
  }
  return 0;
}
