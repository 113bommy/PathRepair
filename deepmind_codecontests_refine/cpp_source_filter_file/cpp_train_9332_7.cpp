#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n, m;
  cin >> n >> m;
  vector<long long> vn(n), vm(m);
  for (int i = 0; i < n; ++i) {
    cin >> vn[i];
  }
  for (int i = 0; i < m; ++i) {
    cin >> vm[i];
  }
  long long banned, mx = -1;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (vn[i] * vm[j] > mx) {
        mx = vn[i] * vm[j];
        banned = i;
      }
    }
  }
  mx = -1;
  for (int i = 0; i < n; ++i) {
    if (i == banned) continue;
    for (int j = 0; j < m; ++j) {
      mx = max(mx, vn[i] * vm[j]);
    }
  }
  cout << mx << endl;
  return 0;
}
