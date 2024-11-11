#include <bits/stdc++.h>
using namespace std;
using ii = pair<int, int>;
using iii = pair<int, ii>;
using ll = long long;
const string FILENAME = "";
const bool FILE_IO = 1;
const int INF = 1000000000;
const int MOD = 1000000000;
void init() {
  if (!FILENAME.empty()) {
    freopen((FILENAME + ".in").c_str(), "r", stdin);
    freopen((FILENAME + ".out").c_str(), "w", stdout);
  }
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  cout.precision(12);
}
void solve() {
  int t;
  cin >> t;
  for (int j = 0; j < t; j++) {
    int n;
    cin >> n;
    ll s = 0, x = 0;
    for (int i = 0; i < n; i++) {
      ll c;
      cin >> c;
      s += c;
      x ^= c;
    }
    cout << 2 << endl << x << " " << s + x << endl;
  }
}
int main() {
  init();
  solve();
  return 0;
}
