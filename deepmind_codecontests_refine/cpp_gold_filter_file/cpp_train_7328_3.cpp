#include <bits/stdc++.h>
using namespace std;
map<pair<long long, int>, pair<long long, int> > h;
pair<long long, int> solve(long long val, int mx) {
  pair<long long, int> ans(0, 0), st(val, mx);
  if (val == 0) return ans;
  if (val < 10) {
    ans = pair<long long, int>(1, 0);
    if (val < mx) ans.second = val - mx;
    return ans;
  }
  map<pair<long long, int>, pair<long long, int> >::iterator it = h.find(st);
  if (it != h.end()) return it->second;
  for (;;) {
    long long p10 = 1;
    for (long long i = val; i >= 10; i /= 10, p10 *= 10)
      ;
    int new_max = mx;
    if (new_max < val / p10) new_max = val / p10;
    pair<long long, int> tt = solve(val % p10, new_max);
    ans.first += tt.first;
    val -= val % p10;
    if (tt.second < 0)
      val += tt.second;
    else {
      val -= new_max;
      ans.first++;
    }
    if (val <= 0) break;
  }
  ans.second = val;
  h[st] = ans;
  return ans;
}
int main(void) {
  for (long long n; cin >> n;) {
    h.clear();
    cout << solve(n, 0).first << endl;
  }
  return 0;
}
