#include <bits/stdc++.h>
using namespace std;
int n, m, l, o, p, q, x, y;
int main() {
  cin >> n >> m >> l >> o >> p >> q;
  vector<pair<int, int> > v;
  for (int i = 0; i < n; ++i) {
    cin >> x >> y;
    v.push_back(make_pair(x, y));
  }
  int s = 0;
  for (int i = 0; i < v.size(); ++i) {
    s += ((v[i].second - v[i].first) * m);
    if (i + 1 != v.size()) {
      int k = v[i + 1].first - v[i].second;
      while (1) {
        if (k < p) {
          s += (k * m);
          break;
        }
        k -= p;
        s += (p * m);
        if (k - q < 0) {
          s += (k * l);
          break;
        }
        k -= q;
        s += (q * l);
        if (k == 0) break;
        s += (k * o);
        break;
      }
    }
  }
  cout << s << endl;
  return 0;
}
