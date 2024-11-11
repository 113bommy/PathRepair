#include <bits/stdc++.h>
using namespace std;
long long solve(long long s, long long x) {
  long long S = s;
  long long X = x;
  int ways = 0;
  int hb = -1;
  for (int i = 0; i < (int)60; ++i) {
    if (x & (1ll << i)) {
      ++ways;
      s -= 1ll << i;
      hb = i;
    }
  }
  if (s < 0) {
    return 0;
  }
  if (hb == -1) {
    if (s % 2 == 0) return 1;
    return 0;
  }
  for (int i = 0; i < (int)60; ++i) {
    if (!(x & (1ll << i))) {
      int bit = i + 1;
      if (s & (1ll << bit)) {
        s -= 1ll << bit;
      }
    }
  }
  if (s == 0) {
    long long ans = 1ll << ways;
    if (X + 0 == S) {
      ans -= 2;
    }
    return ans;
  }
  return 0;
}
int main() {
  long long s, x;
  cin >> s >> x;
  cout << solve(s, x) << endl;
  return 0;
}
