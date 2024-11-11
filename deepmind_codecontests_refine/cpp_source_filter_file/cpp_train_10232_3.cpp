#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int T = 1, n;
  cin >> T;
  while (T--) {
    cin >> n;
    string s;
    cin >> s;
    reverse((s).begin(), (s).end());
    int sz = 1;
    int last = s[0] - '0';
    set<pair<int, int> > ind;
    set<pair<int, int> > siz2;
    set<pair<int, int> > big;
    if (n == 1) {
      cout << 1 << "\n";
      continue;
    }
    for (int i = 1; i < n; ++i) {
      if (s[i] - '0' == last)
        sz++;
      else {
        ind.insert({-i + 1, -sz});
        if (sz == 2) {
          siz2.insert({-i + 1, -sz});
        }
        if (sz > 2) {
          big.insert({-i + 1, -sz});
        }
        last = s[i] - '0';
        sz = 1;
      }
    }
    ind.insert({-n + 1, -sz});
    if (sz == 2) {
      siz2.insert({-n + 1, -sz});
    }
    if (sz > 2) {
      big.insert({-n + 1, -sz});
    }
    int ans = 0;
    while (ind.size()) {
      ans++;
      pair<int, int> par = (*ind.begin());
      int cnt = -par.second;
      int index = -par.first;
      ind.erase(par);
      siz2.erase(par);
      big.erase(par);
      if (cnt > 1) {
        continue;
      }
      if (big.size()) {
        par = (*big.begin());
        cnt = -par.second;
        index = -par.first;
        ind.erase(par);
        big.erase(par);
        ind.insert({par.first, par.second + 1});
        if (cnt > 2) {
          big.insert({par.first, par.second + 1});
        } else if (cnt == 2)
          siz2.insert({par.first, par.second + 1});
      } else if (siz2.size()) {
        par = (*siz2.begin());
        cnt = -par.second;
        index = -par.first;
        ind.erase(par);
        siz2.erase(par);
        ind.insert({par.first, par.second + 1});
      } else {
        par = (*ind.begin());
        ind.erase(par);
      }
    }
    cout << ans << "\n";
  }
}
