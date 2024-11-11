#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
const double EPS = 1e-9;
int main() {
  ios_base::sync_with_stdio(false);
  cout.precision(10);
  unsigned seed = chrono::system_clock::now().time_since_epoch().count();
  minstd_rand0 generator(seed);
  long long n, k;
  cin >> n >> k;
  long long l = 1LL, r = n;
  string ans;
  while (true) {
    long long mid;
    if (r - l <= 2 * k + 1) {
      mid = l + (generator() % (r - l + 1));
      cout << mid << " " << mid << endl;
      cin >> ans;
      if (ans == "No") {
        l = max(1LL, l - k);
        r = min(n, r + k);
      } else
        return 0;
    }
    mid = l + (r - l) / 2;
    cout << l << ' ' << mid << endl;
    cin >> ans;
    if (ans == "Bad") return 0;
    if (ans == "Yes") {
      l = max(1LL, l - k);
      r = min(n, mid + k);
    } else {
      l = max(1LL, mid - k);
      r = min(n, r + k);
    }
  }
  return 0;
}
