#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k, q, i, j;
  int a[100009];
  vector<pair<int, int> > v;
  cin >> n >> k >> q;
  int x;
  for (i = 1; i <= n; i++) {
    cin >> x;
    a[i] = x;
  }
  int type, fr;
  while (q--) {
    cin >> type >> fr;
    if (type == 1) {
      v.push_back(make_pair(a[fr], fr));
      sort(v.begin(), v.end());
      if (v.size() > k) v.pop_back();
    } else {
      int flg = 0;
      for (i = 0; i < v.size(); i++) {
        if (fr == v[i].second) {
          cout << "YES" << endl;
          flg = 1;
          break;
        }
      }
      if (flg == 0) {
        cout << "NO" << endl;
      }
    }
  }
  return 0;
}
