#include <bits/stdc++.h>
using namespace std;
set<pair<int, int> > w;
set<pair<int, int> > b;
int n;
const int Maxn = 1e5 + 100;
set<pair<int, int> >::iterator it;
int main() {
  ios_base::sync_with_stdio(false);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    int x, c;
    cin >> c >> x;
    if (c)
      w.insert(make_pair(x, i));
    else
      b.insert(make_pair(x, i));
  }
  for (int i = 1; i < n; i++) {
    it = w.begin();
    pair<int, int> v = *it;
    it = b.begin();
    pair<int, int> u = *it;
    w.erase(v);
    b.erase(u);
    if (u.first > v.first && w.size() > 0) {
      cout << v.second << ' ' << u.second << ' ' << v.first << endl;
      u.first -= v.first;
      b.insert(make_pair(u.first, u.second));
    } else {
      cout << u.second << ' ' << v.second << ' ' << u.first << endl;
      v.first -= u.first;
      w.insert(make_pair(v.first, v.second));
    }
  }
  return 0;
}
