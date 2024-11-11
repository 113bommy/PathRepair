#include <bits/stdc++.h>
using namespace std;
const long long mod = 998244353;
const long long M = 1e9 + 7;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ;
  int n, m;
  cin >> n >> m;
  unordered_map<int, int> hi;
  while (m--) {
    int u, v;
    cin >> u >> v;
    hi[min(u, v)]++;
  }
  int q;
  cin >> q;
  while (q--) {
    int x;
    cin >> x;
    if (x == 3)
      cout << n - hi.size() << '\n';
    else {
      int y, z;
      cin >> y >> z;
      if (x == 1) {
        hi[min(y, z)]++;
      } else {
        hi[min(y, z)]--;
        if (hi[min(y, z)] == 0) hi.erase(min(y, z));
      }
    }
  }
  return 0;
}
