#include <bits/stdc++.h>
using namespace std;
void solve() {
  int x, y, a, b;
  cin >> x >> y >> a >> b;
  vector<pair<int, int> > tmp;
  for (int i = 1; i <= y; i++) {
    for (int j = 1; j <= x; j++) {
      if (j > i) tmp.push_back({j, i});
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
