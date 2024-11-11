#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long n, i, j, k, a, b, x, MAXX = 1000000000, MAXLEVEL = 10, ans;
  set<long long> s;
  for (a = 0; a <= 9; a++) {
    for (b = 0; b <= 9; b++) {
      vector<set<long long>> plist(MAXLEVEL + 1);
      plist[0].insert(0);
      for (i = 0; i < MAXLEVEL; i++) {
        for (auto p : plist[i]) {
          if (p <= MAXX) {
            s.insert(p);
            plist[i + 1].insert(p * 10 + a);
            plist[i + 1].insert(p * 10 + b);
          }
        }
      }
    }
  }
  s.erase(0);
  cin >> n;
  ans = 0;
  for (auto p : s) {
    if (p <= n) ans++;
  }
  cout << ans << "\n";
  return 0;
}
