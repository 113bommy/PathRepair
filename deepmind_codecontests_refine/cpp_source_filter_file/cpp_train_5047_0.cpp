#include <bits/stdc++.h>
using namespace std;
int main() {
  unsigned long long a, b, ans = 0;
  cin >> a >> b;
  while (a * b > 0) {
    if (a > b) {
      ans += a / b;
      a %= b;
    } else {
      ans += b / a;
      b %= a;
    }
  }
  cout << ans;
}
