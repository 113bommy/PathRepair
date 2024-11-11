#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int t;
  cin >> t;
  while (t--) {
    long long int a, b, c, d, i, j, s = 0, f = 0;
    cin >> a >> b;
    if (a < b) {
      c = b - a;
      if (c % 2 != 0) {
        cout << "1" << endl;
      } else if (c % 2 == 0) {
        if (c > 2) {
          cout << "2" << endl;
        } else {
          cout << c << endl;
        }
      }
    } else if (a > b) {
      c = a - b;
      if (c % 2 == 0) {
        cout << "1" << endl;
      } else if (c % 2 != 0) {
        cout << "2" << endl;
      }
    } else if (a == b) {
      cout << "0" << endl;
    }
  }
  return 0;
}
