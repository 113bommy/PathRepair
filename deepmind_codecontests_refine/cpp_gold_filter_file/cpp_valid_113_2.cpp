#include <bits/stdc++.h>
using namespace std;
const long long modd = (1000LL * 1000LL * 1000LL + 7LL);
int main(int argc, char *argv[]) {
  mt19937 rang(chrono::steady_clock::now().time_since_epoch().count());
  uniform_int_distribution<int> rand_gen(0, modd);
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.precision(12);
  int test_cases = 1;
  for (int t = (1); t < (1) + (test_cases); ++t) {
    int n;
    cin >> n;
    set<long long> a;
    long long sum = 0;
    for (int i = (0); i < (0) + (n); ++i) {
      long long x;
      cin >> x;
      a.insert(x);
      sum += x;
    }
    int m;
    cin >> m;
    for (int i = (0); i < (0) + (m); ++i) {
      long long x;
      cin >> x;
      long long y;
      cin >> y;
      long long bord_low = x, bord_high = sum - y;
      long long ans = 3LL * modd * modd;
      if (bord_high < bord_low) {
        auto it = a.lower_bound(bord_low);
        if (it != a.begin()) {
          --it;
          ans = min(ans, max(bord_low - bord_high, bord_low - *it));
        }
        it = a.lower_bound(bord_low);
        if (it != a.end()) {
          ans = min(ans, *it - bord_high);
        }
      } else {
        auto it = a.lower_bound(bord_low);
        if ((it != a.end()) && (*it <= bord_high)) {
          ans = 0;
        } else {
          if (it != a.begin()) {
            --it;
            ans = min(ans, bord_low - *it);
          }
          it = a.lower_bound(bord_high);
          if (it != a.end()) {
            ans = min(ans, *it - bord_high);
          }
        }
      }
      cout << ans << endl;
    }
  }
  return 0;
}
