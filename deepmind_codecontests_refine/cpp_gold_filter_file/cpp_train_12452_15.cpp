#include <bits/stdc++.h>
using namespace std;
const long long N = 2e5 + 5;
const long long M = 1e9 + 7;
const long long M2 = 998244353;
void input() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
long long n;
string s;
long long go(long long m) {
  long long last = -1;
  map<long long, long long> mp;
  mp[n] = 1;
  string st = s;
  for (long long i = n - 1; i >= 0; i--) {
    if (st[i] == '*') {
      if (last == -1 && !mp[i]) {
        last = i;
      }
    }
    if (st[i] == 'P') {
      if (last != -1 && abs(last - i) > m) {
        return 0;
      } else {
        if (last == -1) {
          for (long long j = min(i, (*mp.begin()).first); j >= 0 && i - j <= m;
               j--) {
            if (st[j] == '*') {
              st[j] = '.';
            }
            mp[j] = 1;
          }
        } else {
          for (long long j = i + 1; j <= last; j++) {
            if (st[j] == '*') {
              st[j] = '.';
            }
            mp[j] = 1;
          }
          long long cnt = m;
          cnt -= abs(last - i);
          long long cnt2 = m;
          cnt2 -= 2 * abs(last - i);
          if (cnt / 2 > cnt2) {
            for (long long j = i - 1; j >= 0 && cnt > 1; j--) {
              cnt -= 2;
              if (st[j] == '*') {
                st[j] = '.';
              }
              mp[j] = 1;
            }
          } else {
            for (long long j = i; j >= 0 && cnt2 >= 0; j--) {
              cnt2--;
              if (st[j] == '*') {
                st[j] = '.';
              }
              mp[j] = 1;
            }
          }
        }
      }
      last = -1;
    }
  }
  for (long long i = 0; i < (long long)n; ++i) {
    if (st[i] == '*') return 0;
  }
  return 1;
}
void solve() {
  cin >> n;
  cin >> s;
  long long l = 0, r = 1e9;
  while (l < r) {
    long long m = (l + r) / 2;
    if (go(m)) {
      r = m;
    } else {
      l = m + 1;
    }
  }
  cout << l << "\n";
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t = 1;
  long long a = 1;
  while (t--) {
    solve();
    a += 1;
  }
}
