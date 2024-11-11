#include <bits/stdc++.h>
using namespace std;
int main() {
  int left = -1e5;
  int right = 1e5;
  int q;
  cin >> q;
  while (q--) {
    int n;
    cin >> n;
    int x, y, l, u, r, d;
    vector<pair<int, int> > vx;
    vector<pair<int, int> > vy;
    for (int i = 0; i < n; i++) {
      cin >> x >> y >> l >> u >> r >> d;
      l = l ? -1e5 : x;
      r = r ? 1e5 : x;
      u = u ? 1e5 : y;
      d = l ? -1e5 : y;
      vx.push_back(make_pair(l, r));
      vy.push_back(make_pair(u, d));
    }
    int ansX = left - 1;
    int ansXX = right + 1;
    int ansY = left - 1;
    int ansYY = right + 1;
    for (int i = 0; i < vx.size(); i++) {
      ansX = max(ansX, vx[i].first);
      ansXX = min(ansXX, vx[i].second);
    }
    for (int i = 0; i < vy.size(); i++) {
      ansY = max(ansY, vy[i].second);
      ansYY = min(ansYY, vy[i].first);
    }
    if (ansX > ansXX || ansY > ansYY)
      cout << 0 << "\n";
    else {
      cout << 1 << " " << ansX << " " << ansY << "\n";
    }
  }
  return 0;
}
