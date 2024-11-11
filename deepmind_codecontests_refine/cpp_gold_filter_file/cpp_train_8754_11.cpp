#include <bits/stdc++.h>
using namespace std;
mt19937 mt(time(0));
int main() {
  long long n, k;
  cin >> n >> k;
  long long lo = 1, hi = n;
  for (int i = 0; i < 100; i++) {
    long long mi = (lo + hi) >> 1;
    cout << mi << ' ' << hi << endl;
    string an;
    cin >> an;
    if (an == "Yes") {
      if (mi == hi) return 0;
      lo = max(1ll, mi - k);
      hi = min(n, hi + k);
    } else if (an == "No") {
      lo = max(1ll, lo - k);
      hi = min(n, mi - 1 + k);
    } else
      return 0;
  }
  while (true) {
    long long t = mt() % (hi - lo + 1);
    cout << lo + t << ' ' << lo + t << endl;
    string an;
    cin >> an;
    if (an == "Yes") {
      return 0;
    } else if (an == "Bad")
      return 0;
    lo = max(1ll, lo - k);
    hi = min(n, hi + k);
    for (int i = 0; i < 5; i++) {
      long long mi = (lo + hi) >> 1;
      cout << mi << ' ' << hi << endl;
      string an;
      cin >> an;
      if (an == "Yes") {
        if (mi == hi) return 0;
        lo = max(1ll, mi - k);
        hi = min(n, hi + k);
      } else if (an == "No") {
        lo = max(1ll, lo - k);
        hi = min(n, mi - 1 + k);
      } else
        return 0;
    }
  }
  return 0;
}
