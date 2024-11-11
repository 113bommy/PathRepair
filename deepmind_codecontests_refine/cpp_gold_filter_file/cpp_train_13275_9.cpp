#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n;
  cin >> n;
  n = -n;
  n = (n % 360 + 360) % 360;
  int best = 400, ans = 0;
  for (int i = 0; i < 4; ++i) {
    int tmp = n + 90 * i;
    int totdev = min(tmp % 360, (720 - tmp) % 360);
    if (totdev < best) {
      best = totdev;
      ans = i;
    }
  }
  cout << ans << endl;
}
