#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int a, b;
  cin >> a >> b;
  long long int ans = 0;
  while (1) {
    if (a == 1) {
      ans += b;
      break;
    }
    if (b == 1) {
      ans += a;
      break;
    }
    if (a > b) {
      ans += a / b;
      a %= b;
    } else {
      ans++;
      b %= a;
    }
  }
  cout << ans << endl;
  return 0;
}
