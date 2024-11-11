#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  srand(time(NULL));
  ;
  int n;
  cin >> n;
  vector<int> v(n);
  for (auto &x : v) cin >> x;
  int m;
  cin >> m;
  vector<int> w(m);
  for (auto &x : w) cin >> x;
  sort(v.begin(), v.end());
  sort(w.begin(), w.end());
  int i = 0, j = 0, res = 0;
  while (i < n && j < m) {
    if (abs(v[i] - w[j]) < 2) {
      ++i, ++j, ++res;
    } else {
      if (v[i] > v[j]) {
        ++j;
      } else {
        ++i;
      }
    }
  }
  cout << res << '\n';
  return 0;
}
