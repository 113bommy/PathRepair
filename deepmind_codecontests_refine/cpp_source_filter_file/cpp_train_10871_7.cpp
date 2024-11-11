#include <bits/stdc++.h>
using namespace std;
template <class T>
int size(const T& a) {
  return a.size();
}
using ll = long long;
bool SetMax(ll& a, ll b) {
  if (a < b) return false;
  a = b;
  return true;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];
  sort(a.begin(), a.end());
  ll best = LLONG_MAX, bbase = -1, bstep = -1;
  for (int base = -20000; base <= 20000; ++base) {
    auto Solve = [&](int m) {
      ll ans = LLONG_MIN;
      for (int i = 0; i < n; ++i) {
        ans = max(ans, abs((1ll * i * m + base) - a[i]));
      }
      return ans;
    };
    int l = 0, r = 10000;
    while (r - l > 2) {
      int m1 = l + (r - l) / 3;
      int m2 = r - (r - l) / 3;
      if (Solve(m1) < Solve(m2))
        r = m2;
      else
        l = m1;
    }
    for (; l <= r; ++l) {
      if (SetMax(best, Solve(l))) {
        bbase = base;
        bstep = l;
      }
    }
  }
  cout << best << '\n' << bbase << ' ' << bstep;
  return 0;
}
