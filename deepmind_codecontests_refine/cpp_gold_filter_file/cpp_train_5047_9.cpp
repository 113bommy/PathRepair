#include <bits/stdc++.h>
using namespace std;
int main() {
  long long a, b;
  while (cin >> a >> b) {
    long long ans = 0;
    while (a && b) {
      ans += a / b;
      long long t = b;
      b = a % b;
      a = t;
    }
    cout << ans << endl;
  }
}
