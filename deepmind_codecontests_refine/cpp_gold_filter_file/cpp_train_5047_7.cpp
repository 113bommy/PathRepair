#include <bits/stdc++.h>
using namespace std;
int main() {
  long long a, b;
  while (cin >> a >> b) {
    long long ans = 0;
    while (a > 0 && b > 0) {
      if (a >= b) {
        ans = ans + a / b;
        a = a % b;
      } else {
        ans = ans + b / a;
        b = b % a;
      }
    }
    cout << ans << endl;
  }
}
