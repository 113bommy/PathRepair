#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, a, b, c;
  while (cin >> n >> a >> b >> c) {
    long long ans;
    if (n < min(a, b)) {
      cout << 0 << endl;
      continue;
    }
    if (b - c < a) {
      if (n >= b)
        ans = (n - b) / (b - c) + 1;
      else
        ans = 0;
      ans += (n - (ans * (b - c))) / a;
    } else {
      ans = n / a;
    }
    cout << ans << endl;
  }
  return 0;
}
