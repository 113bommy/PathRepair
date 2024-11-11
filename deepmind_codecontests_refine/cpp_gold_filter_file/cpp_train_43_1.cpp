#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, a, b, c;
  cin >> n >> a >> b >> c;
  long long ans = 0;
  if (n > a * .5 + b + c * 2) {
    cout << 0 << endl;
    return 0;
  }
  for (int i = 0; i <= b; i++) {
    for (int j = 0; j <= c; j++) {
      long long x = n - i - j * 2;
      if (x >= 0 && x * 2 <= a) {
        ans++;
      }
    }
  }
  cout << ans << endl;
  return 0;
}
