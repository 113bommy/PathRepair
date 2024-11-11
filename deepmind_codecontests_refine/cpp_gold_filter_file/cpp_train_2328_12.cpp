#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, v;
  cin >> n >> m >> v;
  if (m < n - 1) {
    cout << -1 << endl;
    return 0;
  }
  int connect = 1;
  if (v == connect) ++connect;
  long long sz = (long long)(n - 2) * (n - 1) / 2;
  ++sz;
  if (sz < m) {
    cout << -1 << endl;
    return 0;
  }
  vector<int> lft;
  lft.push_back(v);
  for (int i = 2; i <= n; i++) {
    if (i == v || i == connect) continue;
    lft.push_back(i);
  }
  cout << v << ' ' << connect << endl;
  --m;
  for (int len = 1; len < lft.size(); len++) {
    for (int i = 0; i + len < lft.size(); i++) {
      if (m == 0) {
        return 0;
      }
      cout << lft[i] << ' ' << lft[i + len] << endl;
      --m;
    }
  }
  return 0;
}
