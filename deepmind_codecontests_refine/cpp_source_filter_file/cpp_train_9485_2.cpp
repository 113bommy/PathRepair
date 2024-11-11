#include <bits/stdc++.h>
using namespace std;
map<int, int> ps;
int main() {
  int n;
  cin >> n;
  int k;
  cin >> k;
  int sz = (1 << k) - 1l;
  int now = 0;
  ++ps[0];
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    now ^= x;
    ++ps[min(x, x ^ sz)];
  }
  long long int res = n * 1ll * (n + 1) / 2;
  for (auto &p : ps) {
    int a = p.second;
    long long int a1 = a / 2, a2 = a - a1;
    res -= a1 * (a1 - 1) / 2;
    res -= a2 * (a2 - 1) / 2;
  }
  cout << res << endl;
  return 0;
}
