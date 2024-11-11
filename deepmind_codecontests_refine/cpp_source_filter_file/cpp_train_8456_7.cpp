#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long int n, a = 2;
    cin >> n;
    while (a > 0) {
      a = 2 * a;
      a = a - 1;
      if (n % a == 0)
        break;
      else
        a = a + 1;
    }
    cout << n / a + 1 << endl;
  }
}
