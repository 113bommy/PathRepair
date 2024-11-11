#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    long long n, ans = 0, a;
    cin >> n;
    for (int j = 1; j < 60; j++) {
      if (n % 2 == 0) {
        a = n / 2;
      } else {
        a = (n / 2) + 1;
      }
      ans = ans + (j * a);
      n = n - a;
      if (n == 0) {
        break;
      }
    }
    cout << ans << endl;
  }
}
