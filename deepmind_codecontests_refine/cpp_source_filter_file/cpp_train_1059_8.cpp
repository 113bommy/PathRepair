#include <bits/stdc++.h>
using namespace std;
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    long long k;
    cin >> k;
    if (k <= 56) {
      string l = "11212312341234512345612345671234567812345678912345678910";
      cout << l[k - 1] << endl;
      continue;
    }
    long long n = 1;
    long long tmp = k;
    long long i = 1;
    long long j = 1;
    long long imp = 9;
    long long pos = 0;
    long long cnt = 1;
    while (k > 0) {
      k -= i;
      if (cnt % imp == 0) {
        imp = imp * 10 + 9;
        j++;
      }
      i += j;
      cnt++;
      if (k - i < 0) {
        i -= j;
        break;
      }
    }
    string tmp1 = "";
    long long plo = 1;
    while (tmp1.size() <= i) {
      tmp1 += to_string(plo);
      plo++;
    }
    cout << tmp1[k - 1] << endl;
  }
}
