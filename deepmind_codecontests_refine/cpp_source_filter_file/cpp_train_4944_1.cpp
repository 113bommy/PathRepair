#include <bits/stdc++.h>
using namespace std;
const int M = 1e9 + 7;
int V, E, i, j, k, u, v, x, y, p, q, r, t, n;
vector<int> *g;
vector<bool> sn;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n;
  set<pair<int, int> > s;
  cin >> p;
  deque<int> c1, c2;
  for (int i = 0; i < p; i++) {
    cin >> x;
    c1.push_back(x);
  }
  cin >> q;
  for (int i = 0; i < q; i++) {
    cin >> x;
    c2.push_back(x);
  }
  bool ans = false;
  k = 0;
  int w = 0;
  while (k < 50) {
    if (c1.empty()) {
      w = 2;
      ans = true;
      break;
    }
    if (c2.empty()) {
      w = 1;
      ans = true;
      break;
    }
    x = c1.front();
    c1.pop_front();
    y = c2.front();
    c2.pop_front();
    if (x > y) {
      c1.push_back(y);
      c1.push_back(x);
    } else {
      c2.push_back(x);
      c2.push_back(y);
    }
    k++;
  }
  if (ans) {
    cout << k << " " << w << endl;
  } else {
    cout << -1 << endl;
  }
}
