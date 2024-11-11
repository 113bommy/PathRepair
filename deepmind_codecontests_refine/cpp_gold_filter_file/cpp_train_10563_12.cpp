#include <bits/stdc++.h>
using namespace std;
int main() {
  ifstream fin("input.txt");
  int n, m = 100000, a, i, j, q, c1 = 0, cn, t, w, x, y;
  string c, d;
  map<string, string> mp;
  cin >> n >> m;
  for (i = 0; i < m; i++) {
    cin >> c >> d;
    mp[c] = d.length() < c.length() ? d : c;
    mp[d] = mp[c];
  }
  for (i = 0; i < n; i++) {
    cin >> c;
    cout << mp[c] << " ";
  }
  cout << endl;
  return 0;
}
