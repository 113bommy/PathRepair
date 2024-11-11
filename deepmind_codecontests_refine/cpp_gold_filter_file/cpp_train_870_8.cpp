#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  vector<int> v(t);
  for (auto &i : v) {
    cin >> i;
  }
  map<int, int> m;
  for (int i = 0; i < t; i++) {
    m[i + 1] = v[i];
  }
  int n;
  cin >> n;
  if (n == 0) {
    for (auto &i : v) {
      cout << i << endl;
    }
    return 0;
  }
  while (n--) {
    int wire;
    int bird;
    cin >> wire >> bird;
    if (wire != t && wire != 1) {
      m[wire + 1] = m[wire + 1] + (m[wire] - bird);
      m[wire - 1] = m[wire - 1] + ((m[wire] - 1) - (m[wire] - bird));
      m[wire] = 0;
    } else {
      if (wire == t) {
        m[wire - 1] = m[wire - 1] + ((m[wire] - 1) - (m[wire] - bird));
        m[wire] = 0;
      }
      if (wire == 1) {
        m[wire + 1] = m[wire + 1] + (m[wire] - bird);
        m[wire] = 0;
      }
    }
  }
  if (t == 1 && n != 0) {
    cout << 0;
  } else {
    for (auto &i : m) {
      cout << i.second << endl;
    }
  }
}
