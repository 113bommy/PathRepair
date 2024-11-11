#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, x;
    cin >> n >> x;
    vector<pair<int, int> > v;
    for (int i = 0; i < n; i++) {
      int k, l;
      cin >> k >> l;
      v.push_back(make_pair(k, l));
    }
    int j = 0, ma = -1, b = 0;
    for (int i = 0; i < n; i++) {
      b = max(b, v[i].first);
      if ((v[i].first - v[i].second) > ma) {
        ma = max(v[i].first - v[i].second, ma);
        j = v[i].first;
      } else if ((v[i].first - v[i].second) == ma) {
        if (v[i].first > j) {
          j = v[i].first;
        }
      }
    }
    if (b >= x) {
      cout << "1" << endl;
    } else if (ma > 0) {
      if ((x - b) % ma == 0) {
        cout << (x - b) / ma + 1 << endl;
      } else {
        cout << (x - b) / ma + 2 << endl;
      }
    } else {
      cout << "-1" << endl;
    }
  }
  return 0;
}
