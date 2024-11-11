#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, T, n, a = 2;
  cin >> n;
  if (n > 9) {
    long long ans = 9;
    for (t = 100; t <= n; t *= 10, a++) {
      ans += ((t) - (t / 10)) * a;
    }
    t /= 10;
    ans += (n - t + 1) * a;
    cout << ans;
  } else
    cout << n;
}
