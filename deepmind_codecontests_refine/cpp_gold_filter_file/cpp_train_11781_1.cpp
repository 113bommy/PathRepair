#include <bits/stdc++.h>
using namespace std;
int main() {
  set<pair<int, int>> exp, v;
  int mod, n;
  cin >> mod >> n;
  pair<int, int> t;
  for (int i = 0; i < n; i++) {
    cin >> t.first >> t.second;
    if (t.first > t.second) {
      swap(t.first, t.second);
    }
    t.first--;
    t.second--;
    exp.insert(t);
  }
  for (int i = 1; i < mod; i++) {
    if (mod % i == 0) {
      for (auto it : exp) {
        t = it;
        t.first = (t.first + i) % mod;
        t.second = (t.second + i) % mod;
        if (t.first > t.second) {
          swap(t.first, t.second);
        }
        v.insert(t);
      }
      int y = 1;
      for (auto it = exp.begin(), ij = v.begin();
           it != exp.end() && ij != v.end(); it++, ij++) {
        if (*it != *ij) {
          y = 0;
          break;
        }
      }
      if (y) {
        cout << "Yes" << endl;
        return 0;
      }
      v.clear();
    }
  }
  cout << "No" << endl;
  return 0;
}
