#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, x = 0, y = 0;
  set<pair<int, int> > grises;
  cin >> n;
  for (int i = 0; i < n; i++) {
    grises.insert(pair<int, int>(x, y));
    grises.insert(pair<int, int>(x + 1, y));
    grises.insert(pair<int, int>(x - 1, y));
    grises.insert(pair<int, int>(x, y + 1));
    grises.insert(pair<int, int>(x, y - 1));
    grises.insert(pair<int, int>(x - 1, y + 1));
    grises.insert(pair<int, int>(x + 1, y - 1));
    x++;
    y--;
  }
  cout << grises.size() << "\n";
  for (auto g : grises) {
    cout << g.first << " " << g.second << "\n";
  }
  return 0;
}
