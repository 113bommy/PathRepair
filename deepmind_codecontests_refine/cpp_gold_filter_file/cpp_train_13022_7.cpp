#include <bits/stdc++.h>
using namespace std;
signed main() {
  int n, m, cym = 0;
  cin >> n >> m;
  vector<int> v(m, 0);
  int a, b;
  for (int i = 0; i < n; i++) {
    cin >> a >> b;
    for (int j = a - 1; j < b; j++) v[j]++;
  }
  for (int i = 0; i < v.size(); i++) {
    if (v[i] == 0) cym++;
  }
  cout << cym << endl;
  for (int i = 0; i < v.size(); i++) {
    if (v[i] == 0) cout << i + 1 << " ";
  }
  return 0;
}
