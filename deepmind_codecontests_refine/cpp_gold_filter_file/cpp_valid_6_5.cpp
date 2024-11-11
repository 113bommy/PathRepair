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
  int cnt = 0;
  while (m--) {
    int u, v;
    cin >> u >> v;
    if (!hi[min(u, v)]) cnt++;
    hi[min(u, v)]++;
  }
  int q;
  cin >> q;
  while (q--) {
    int x;
    cin >> x;
    if (x == 3)
      cout << n - cnt << '\n';
    else {
      int y, z;
      cin >> y >> z;
      if (x == 1) {
        if (!hi[min(y, z)]) cnt++;
        hi[min(y, z)]++;
      } else {
        hi[min(y, z)]--;
        if (!hi[min(y, z)]) cnt--;
      }
    }
  }
  return 0;
}
