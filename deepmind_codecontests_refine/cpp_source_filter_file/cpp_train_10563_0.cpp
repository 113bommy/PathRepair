#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n, m;
  cin >> n >> m;
  string x, y;
  map<string, string> mp;
  for (int i = 0; i < m; i++) {
    cin >> x >> y;
    mp[x] = y;
  }
  for (int i = 0; i < n; i++) {
    cin >> x;
    cout << ((x.length() < mp[x].length()) ? x : mp[x]) << " ";
  }
  return 0;
}
