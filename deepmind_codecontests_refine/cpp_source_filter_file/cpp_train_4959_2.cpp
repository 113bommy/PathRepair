#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<int> v(n);
  for (auto &e : v) cin >> e;
  bool ok = true;
  for (int i = 1; i < v.size(); ++i) {
    if (v[i] % v[0] != 0) {
      ok = false;
    }
  }
  if (!ok) {
    cout << -1 << endl;
  } else {
    cout << 2 * n + 1 << endl;
    for (int i = 0; i < v.size() - 1; ++i) {
      cout << v[i] << ' ' << v[0] << ' ';
    }
    cout << v.back() << endl;
  }
  return 0;
}
