#include <bits/stdc++.h>
using namespace std;
bool ss(const pair<int, int> &a, const pair<int, int> &b) {
  return (a.second > b.second);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int k;
  cin >> k;
  while (k--) {
    int n;
    cin >> n;
    if (n <= 1) {
      int x;
      cin >> x;
      cout << 0 << endl;
      continue;
    } else {
      unordered_map<int, int> m;
      int d = 0;
      for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (!m[x]) {
          d += 1;
        }
        m[x] += 1;
      }
      vector<pair<int, int>> v;
      for (auto it = m.begin(); it != m.end(); it++) {
        v.push_back(make_pair(it->first, it->second));
      }
      sort(v.begin(), v.end(), ss);
      int f = 0;
      for (auto it = v.begin(); it != v.end(); it++) {
        int rep = it->second;
        if (d - 1 == rep) {
          cout << rep << endl;
          f = 1;
          break;
        }
        if (rep == 1) {
          cout << 1 << endl;
          f = 1;
          break;
        }
        cout << min(d, rep - 1) << endl;
        f = 1;
        break;
      }
      if (f)
        continue;
      else {
        cout << 1 << endl;
      }
    }
  }
}
