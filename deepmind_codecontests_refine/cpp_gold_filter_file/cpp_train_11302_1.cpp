#include <bits/stdc++.h>
using namespace std;
bool check(map<pair<int, int>, char>& m, pair<int, int> k, char no) {
  map<pair<int, int>, char>::iterator it1, it2;
  it2 = it1 = m.upper_bound(k);
  if (it1 != m.end() && it1->second != no) return true;
  if (m.size() && it1 != m.begin()) {
    it2--;
    if (it2->second != no) return true;
  }
  return false;
}
int main() {
  int n;
  cin >> n;
  map<pair<int, int>, char> r1, r2, b1, b2;
  int x, y, rx, ry;
  cin >> rx >> ry;
  char t;
  for (int i = 0; i < n; i++) {
    cin >> t >> x >> y;
    pair<int, int> pa = make_pair(x, y);
    if (x == rx)
      r1[pa] = t;
    else if (y == ry)
      r2[pa] = t;
    if (rx - x == ry - y)
      b1[pa] = t;
    else if (rx - x == y - ry)
      b2[pa] = t;
  }
  pair<int, int> king = make_pair(rx, ry);
  bool sol = check(r1, king, 'B') || check(r2, king, 'B') ||
             check(b1, king, 'R') || check(b2, king, 'R');
  if (sol)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
  return 0;
}
