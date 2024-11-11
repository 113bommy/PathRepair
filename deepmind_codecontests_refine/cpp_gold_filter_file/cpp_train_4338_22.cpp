#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 9;
const int INFINT = 1e9 + 9;
const long long INFLL = 1e18 + 9;
const long double EPS = 1e-12;
const char C = 'a';
const long long MOD = 1e9 + 7;
const long long BASE = 31;
vector<int> E, L;
int main() {
  ios::sync_with_stdio(0);
  int n, m, cl, ce, v, q, i1, j1, i2, j2;
  vector<int>::iterator it;
  cin >> n >> m >> cl >> ce >> v;
  E.resize(ce);
  L.resize(cl);
  for (int i = 0; i < (cl); i++) cin >> L[i];
  for (int i = 0; i < (ce); i++) cin >> E[i];
  cin >> q;
  while (q) {
    cin >> i1 >> j1 >> i2 >> j2;
    if (i1 == i2)
      cout << abs(j1 - j2) << '\n';
    else {
      if (j2 < j1) {
        swap(j2, j1);
        swap(i2, i1);
      }
      int ans = INFINT * 2, cur = 0;
      it = upper_bound(E.begin(), E.end(), j1);
      if (it != E.begin()) {
        it--;
        cur += abs(*it - j1);
        cur += abs(i1 - i2) / v;
        if (abs(i1 - i2) % v) cur++;
        cur += abs(*it - j2);
        ans = min(ans, cur);
      }
      it = lower_bound(E.begin(), E.end(), j1);
      if (it != E.end()) {
        cur = 0;
        cur += abs(*it - j1);
        cur += abs(i1 - i2) / v;
        if (abs(i1 - i2) % v) cur++;
        cur += abs(*it - j2);
        ans = min(ans, cur);
      }
      it = upper_bound(L.begin(), L.end(), j1);
      if (it != L.begin()) {
        it--;
        cur = 0;
        cur += abs(*it - j1);
        cur += abs(i1 - i2);
        cur += abs(*it - j2);
        ans = min(ans, cur);
      }
      it = lower_bound(L.begin(), L.end(), j1);
      if (it != L.end()) {
        cur = 0;
        cur += abs(*it - j1);
        cur += abs(i1 - i2);
        cur += abs(*it - j2);
        ans = min(ans, cur);
      }
      cout << ans << '\n';
    }
    q--;
  }
  cin.get();
  return 0;
}
