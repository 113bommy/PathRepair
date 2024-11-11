#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, b, d, a, now = 0, ans = 0;
  cin >> n >> b >> d;
  for (int i = 0; i < n; i++) {
    cin >> a;
    if (a <= b) now += a;
    if (now > d) {
      now = 0;
      ans++;
    }
  }
  cout << ans << endl;
  return 0;
}
