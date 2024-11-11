#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
const int mod = 998244353;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.precision(10);
  cout << fixed;
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> v;
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      v.push_back(x);
    }
    bool f = false;
    for (int i = 0; i < n - 1; i++) {
      if (abs(v[i] - v[i + 1]) >= n) {
        cout << "YES\n";
        cout << i + 1 << " " << i + 2 << endl;
        f = true;
        break;
      }
    }
    if (!f) cout << "NO\n";
  }
}
