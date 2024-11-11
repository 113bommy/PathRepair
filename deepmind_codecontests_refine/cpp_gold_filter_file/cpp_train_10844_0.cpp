#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 1;
const int NN = 1e3 + 1;
const long long MOD = 1e9 + 7;
const long long oo = 1e18 + 7;
void query() {
  string a, b;
  cin >> a >> b;
  int n = (int)(a).size(), m = (int)(b).size();
  vector<pair<char, int>> as, bs;
  int cnt = 1;
  for (int i = 1; i <= n; i++) {
    if (a[i] != a[i - 1]) {
      as.push_back(make_pair(a[i - 1], cnt));
      cnt = 1;
    } else {
      cnt++;
    }
  }
  cnt = 1;
  for (int i = 1; i <= m; i++) {
    if (b[i] != b[i - 1]) {
      bs.push_back(make_pair(b[i - 1], cnt));
      cnt = 1;
    } else {
      cnt++;
    }
  }
  if ((int)(as).size() != (int)(bs).size()) {
    cout << "NO" << endl;
    return;
  }
  for (int i = 0; i < (int)(as).size(); i++) {
    if (as[i].first != bs[i].first) {
      cout << "NO" << endl;
      return;
    } else {
      if (as[i].second > bs[i].second) {
        cout << "NO" << endl;
        return;
      }
    }
  }
  cout << "YES" << endl;
}
void solve() {
  int q;
  cin >> q;
  while (q--) {
    query();
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cout.precision(10);
  solve();
  cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
  return 0;
}
