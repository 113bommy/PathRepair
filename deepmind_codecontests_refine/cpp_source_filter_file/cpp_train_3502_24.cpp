#include <bits/stdc++.h>
using namespace std;
int main() {
  string a, b, c, d;
  map<string, string> mp;
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> a >> b;
    mp[b] = a;
  }
  for (int i = 0; i < m; i++) {
    cin >> c >> d;
    d.pop_back();
    cout << c << " " << d << " #" << mp[d] << endl;
  }
  return 0;
}
