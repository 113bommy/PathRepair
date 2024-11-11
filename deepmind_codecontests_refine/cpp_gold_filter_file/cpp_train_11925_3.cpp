#include <bits/stdc++.h>
int f(int dd) {
  int ans = 1;
  int64_t x = 7;
  while (dd > x) {
    ans++;
    x *= 7;
  }
  return ans;
}
int n, m;
int dh, dm;
int64_t solve(int dd, std::set<int>& used, int64_t valh, int64_t valm) {
  if (dd == 0)
    return (valh < n && valm < m ? 1 : 0);
  else {
    int64_t ans = 0;
    for (int i = 0; i < 7; ++i) {
      if (used.count(i) == 0) {
        used.insert(i);
        if (dd > dm) {
          int64_t vh = valh * 7 + i;
          if (vh < n) ans += solve(dd - 1, used, vh, valm);
        } else {
          int64_t vm = valm * 7 + i;
          if (vm < m) ans += solve(dd - 1, used, valh, vm);
        }
        used.erase(i);
      }
    }
    return ans;
  }
}
int main() {
  std::cin >> n >> m;
  dh = f(n);
  dm = f(m);
  int ds = dh + dm;
  if (ds > 7) {
    std::cout << 0 << '\n';
  } else {
    std::set<int> st;
    std::cout << solve(ds, st, 0, 0) << '\n';
  }
  return 0;
}
