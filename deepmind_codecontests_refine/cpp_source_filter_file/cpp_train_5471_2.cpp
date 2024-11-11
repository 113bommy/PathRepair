#include <bits/stdc++.h>
using namespace std;
const long long MAXN = 101 * 1001;
set<long long> s;
map<long long, long long> cnt;
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  s.insert(0);
  long long q, x;
  char ch;
  cin >> q;
  while (q--) {
    cin >> ch >> x;
    if (ch == '+') {
      if (cnt[x] == 0) s.insert(x);
      cnt[x]++;
      ;
    }
    if (ch == '-') {
      cnt[x]--;
      if (cnt[x] == 0) s.erase(x);
    }
    if (ch == '?') {
      long long cur = 0;
      for (long long i = 30; i > -1; i--) {
        if (x & (1 << i)) {
          set<long long>::iterator it = s.lower_bound(cur);
          long long y = *it, f = 0;
          if (y & (1 << i)) f = 1;
          if (f) {
            cur += (1 << i);
          }
        } else {
          set<long long>::iterator it = s.lower_bound(cur + (1 << i));
          if (it == s.end()) continue;
          long long y = *it, f = 0;
          if (y > (cur + (1 << (i + 1)))) f = 1;
          if (f) continue;
          cur += (1 << i);
        }
      }
      cout << (cur ^ x) << '\n';
    }
  }
}
