#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  t = 1;
  while (t--) {
    int x, y, a, b;
    cin >> x >> y >> a >> b;
    std::vector<int> v, v1;
    std::vector<pair<int, int>> v2;
    while (a < x + 1) {
      v.push_back(a);
      a++;
    }
    while (b < y + 1) {
      v1.push_back(b);
      b++;
    }
    for (int i = 0; i <= v.size() - 1; i++) {
      for (int j = 0; j <= v1.size() - 1; j++) {
        if (v[i] > v1[j]) v2.push_back({v[i], v[j]});
      }
    }
    if (v2.size() == 0) {
      cout << "0";
      return 0;
    }
    cout << v2.size() << "\n";
    for (auto x : v2) {
      cout << x.first << " " << x.second << "\n";
    }
  }
  return 0;
}
