#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  for (int i = 1; i <= t; i++) {
    int n, s;
    cin >> n >> s;
    if (n == 1)
      cout << n << endl;
    else if (n == 2)
      cout << s / 2 << endl;
    else if (n > 2) {
      if (n % 2 == 0) {
        n = n - (n - 1) / 2;
        cout << s / n << endl;
      } else {
        n = (n + 1) / 2;
        cout << s / n << endl;
      }
    }
  }
}
