#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  string s, t;
  cin >> s >> t;
  int ans = n;
  vector<int> position, tposition;
  for (int i = 0; i < m - n + 1; i++) {
    string tmp = t.substr(i, n);
    tposition.clear();
    int c = 0;
    for (int j = 0; j < n; j++) {
      if (s[j] != tmp[j]) {
        c++;
        tposition.push_back(j);
      }
    }
    if (ans > c) {
      ans = c;
      if (ans == 0) {
        cout << ans << endl;
        return 0;
      }
      position = tposition;
    }
  }
  cout << ans << endl;
  for (int i = 0; i < position.size(); i++) {
    cout << position[i] + 1;
    if (i < ans - 1) cout << " ";
  }
  cout << endl;
  return 0;
}
