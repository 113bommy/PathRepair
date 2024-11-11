#include <bits/stdc++.h>
using namespace std;
int main() {
  ios ::sync_with_stdio(false);
  cin.tie(NULL);
  cout << (fixed) << setprecision(6);
  long long t, a, b;
  while (cin >> t >> a >> b) {
    if (t == a && a != b)
      cout << 0 << endl;
    else if (t == a && a == b) {
      if (t == 1)
        cout << "inf" << endl;
      else
        cout << 2 << endl;
    } else if (a == b)
      cout << 1 << endl;
    else if (a > b)
      cout << 0 << endl;
    else if (t > a)
      cout << 0 << endl;
    else {
      int res = 0;
      if ((b - a) % (a - t) == 0) {
        vector<long long> repa, repb;
        if (t == 1) {
          while (b) {
            repb.push_back(b % a);
            b /= a;
          }
          long long sumb = 0;
          for (__typeof(repb.begin()) it = repb.begin(); it != repb.end(); ++it)
            sumb += *it;
          if (sumb == 0 || a == sumb) ++res;
        } else {
          while (b) {
            repb.push_back(b % a);
            b /= a;
          }
          while (a) {
            repa.push_back(a % t);
            a /= t;
          }
          if (repa == repb) ++res;
        }
      }
      cout << res << endl;
    }
  }
  return 0;
}
