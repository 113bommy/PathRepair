#include <bits/stdc++.h>
const int INF = 1e9 + 1;
const int MOD = 1e9 + 7;
const int N = 1e6 + 1;
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  int n;
  cin >> n;
  int x, y;
  set<pair<int, int> > s, b;
  for (int i = 1; i <= n; i++) {
    cin >> x >> y;
    if (x < y) {
      s.insert(make_pair(x, i));
    } else {
      b.insert(make_pair(-1 * y, i));
    }
  }
  if (s.size() > b.size()) {
    cout << s.size() << endl;
    pair<int, int> p;
    while (s.size() > 0) {
      p = *s.begin();
      cout << p.second << " ";
      s.erase(p);
    }
  } else {
    cout << b.size() << endl;
    pair<int, int> p;
    while (b.size() > 0) {
      p = *b.begin();
      cout << p.second << " ";
      b.erase(p);
    }
  }
  cout << endl;
}
