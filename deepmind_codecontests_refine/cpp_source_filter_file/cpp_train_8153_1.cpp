#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
vector<int> v;
vector<pair<int, int> > u;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, x = 0, y;
  cin >> n;
  for (int i = 0; i <= n; i++) {
    if (i != n)
      cin >> y;
    else
      y = 0;
    if (y > x) {
      for (int j = 0; j < y - x; j++) v.push_back(i);
    } else {
      for (int j = 0; j < x - y; j++) {
        u.push_back(pair<int, int>(v[v.size() - 1], i));
        v.pop_back();
      }
    }
    x = y;
  }
  cerr << u.size() << "\n";
  for (int i = 0; i < u.size(); i++)
    cout << u[i].first + 1 << " " << u[i].second << "\n";
}
