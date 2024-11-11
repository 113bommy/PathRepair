#include <bits/stdc++.h>
using namespace std;
int main(void) {
  long long t;
  cin >> t;
  while (t--) {
    long long k, rw, cl;
    cin >> k;
    long long cp = sqrt(k);
    long long r = (cp * cp == k) ? cp : cp + 1;
    long long c = r * r;
    long long s = (r * r - r + 1);
    if (k < s) {
      cl = r;
      rw = (r - (s - k));
    } else if (k > s) {
      rw = r;
      cl = (r + (s - k));
    } else {
      rw = r;
      cl = r;
    }
    cout << rw << " " << cl << endl;
  }
}
