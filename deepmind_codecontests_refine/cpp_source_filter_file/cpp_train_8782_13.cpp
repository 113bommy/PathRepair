#include <bits/stdc++.h>
using namespace std;
int main() {
  int m, q, n, a;
  int mn = 1e9;
  cin >> m;
  for (int i = 0; i < m; i++) cin >> q, mn = min(q, mn);
  cin >> n;
  int s = 0;
  vector<int> v(n);
  for (int j = 0; j < n; j++) cin >> v[j];
  sort(v.rbegin(), v.rend());
  int t = 0;
  for (int i = 0; i < v.size(); i++) {
    t++;
    s += v[i];
    if (t == q) {
      i += 2;
      t = 0;
    }
  }
  cout << s << endl;
  return 0;
}
