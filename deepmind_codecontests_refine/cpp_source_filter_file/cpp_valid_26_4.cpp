#include <bits/stdc++.h>
using namespace std;
const long long INF = 1000000007;
const long long N = 10000000;
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cout.precision(numeric_limits<double>::max_digits10);
  long long q;
  cin >> q;
  while (q--) {
    string s;
    cin >> s;
    string s1 = s;
    long long i = 0, j = 1;
    long long scrA = 0, scrB = 0, ans1 = 10, ans2 = 10;
    while (i < 10) {
      if (i % 2 == 0) {
        if (s[i] == '1' || s[i] == '?') scrA++;
        if (scrB + (5 - i / 2) < scrA) {
          ans1 = i + 1;
          break;
        }
        i++;
      }
      if (i % 2) {
        if (s[i] == '1') scrB++;
        if (scrB + (5 - i / 2) < scrA) {
          ans1 = i + 1;
          break;
        }
        i++;
      }
    }
    i = 0;
    scrA = 0;
    scrB = 0;
    while (i < 10) {
      if (i % 2 == 0) {
        if (s[i] == '1') scrA++;
        if (scrA + (4 - i / 2) < scrB) {
          ans2 = i + 1;
          break;
        }
        i++;
      }
      if (i % 2) {
        if (s[i] == '?' || s[i] == '1') scrB++;
        if (scrA + (4 - i / 2) < scrB) {
          ans2 = i + 1;
          break;
        }
        i++;
      }
    }
    cout << min(ans1, ans2) << '\n';
  }
  return 0;
}
