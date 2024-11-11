#include <bits/stdc++.h>
using namespace std;
int n;
vector<string> v;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    cin >> n;
    v.assign(n, "");
    int counte_0 = 0;
    int counte_1 = 0;
    for (auto &x : v) cin >> x;
    for (auto &x : v) {
      for (auto &y : x) {
        if (y == '0')
          counte_0++;
        else
          counte_1++;
      }
    }
    int ans = 0;
    multiset<int> lengs;
    for (auto &x : v) {
      lengs.insert(x.size());
    }
    for (auto &x : lengs) {
      if (x % 2 == 1)
        ans++;
      else {
        bool good = true;
        for (int i = 0; i < x / 2; i++) {
          if (counte_0 >= 2)
            counte_0 -= 2;
          else if (counte_1 >= 2)
            counte_1 -= 2;
          else {
            good = false;
            break;
          }
        }
        if (good) ans++;
      }
    }
    cout << ans << '\n';
  }
}
