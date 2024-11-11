#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, h, k;
  cin >> n >> h >> k;
  long long int ans = 0;
  int taken = 0;
  while (n--) {
    int now;
    cin >> now;
    if (now + taken <= h) {
      taken += now;
    } else {
      int tmp = taken / k;
      taken -= tmp * k;
      ans += tmp;
      if (taken + now > h) {
        ans++;
        taken = 0;
      }
      taken += now;
    }
  }
  ans += (taken + k - 1) / k;
  cout << ans << endl;
}
