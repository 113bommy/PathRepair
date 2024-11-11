#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    long long n, a = 0, b = 0;
    cin >> n;
    if (n == 1) {
      cout << 0 << endl;
    } else {
      while (n % 3 == 0) {
        n /= 3;
        a++;
      }
      while (n % 2 == 0) {
        n /= 2;
        b++;
      }
      if (a >= b && n == 1) {
        cout << a + a - b << endl;
        ;
      } else {
        cout << -1 << endl;
      }
    }
  }
  return 0;
}
