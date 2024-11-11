#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    string str;
    cin >> str;
    map<long long, long long> mp;
    mp[0] = -1;
    long long pre = 0;
    long long max = INT_MAX;
    long long l, r;
    for (long long i = 0; i < n; i++) {
      char x = str[i];
      if (x == 'L') {
        pre++;
      } else if (x == 'R') {
        pre--;
      } else if (x == 'U') {
        pre += INT_MAX;
      } else {
        pre -= INT_MAX;
      }
      if (mp.count(pre)) {
        long long cur = i - mp[pre];
        if (cur < max) {
          l = mp[pre] + 2;
          r = i + 1;
          max = cur;
        }
      }
      mp[pre] = i;
    }
    if (max == INT_MAX) {
      cout << -1 << endl;
    } else {
      cout << l << " " << r << endl;
    }
  }
}
