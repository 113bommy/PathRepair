#include <bits/stdc++.h>
using namespace std;
void solve() {
  int x, y, a, b;
  cin >> x >> y >> a >> b;
  vector<pair<int, int> > tmp;
  for (int i = a; i <= x; i++) {
    for (int j = b; j <= y; j++) {
      if (i > j) tmp.push_back({i, j});
    }
  }
  cout << tmp.size() << endl;
  for (pair<int, int> p : tmp) {
    cout << p.first << " " << p.second << endl;
  }
}
int main() {
  int tt = 1;
  while (tt--) {
    solve();
  }
}
