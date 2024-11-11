#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int &x : a) cin >> x;
  int basis[30]{};
  auto insert = [&](int x) {
    for (int bit = 0; bit < 30; ++bit) {
      if (~x >> bit & 1) continue;
      if (basis[bit] == 0) {
        basis[bit] = x;
        return true;
      }
      x ^= basis[bit];
    }
    return false;
  };
  int ans = 0, pre = 0;
  for (int x : a) {
    pre ^= x;
    ans += insert(pre);
  }
  if (pre == 0) {
    cout << "-1\n";
    return 0;
  }
  cout << ans << '\n';
}
