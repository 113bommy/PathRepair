#include <bits/stdc++.h>
using namespace std;
int main() {
  map<int, int> m;
  map<int, bool> mb;
  int n, k, q;
  cin >> n >> k >> q;
  vector<int> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }
  for (int i = 0; i < q; i++) {
    int t, id;
    cin >> t;
    cin >> id;
    if (t == 1) {
      m[v[id - 1]] = id;
      mb[id] = true;
      if (m.size() > k) {
        mb[m.begin()->second] = false;
        m.erase(m.begin()->first);
      }
    } else {
      if (mb[id]) {
        cout << "YES" << endl;
      } else {
        cout << "NO" << endl;
      }
    }
  }
  return 0;
}
