#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int main() {
  ios_base::sync_with_stdio(false);
  int n, r, u;
  cin >> n >> r;
  vector<pair<int, double> > v(n);
  for (int i = 0; i < n; i++) {
    cin >> u;
    v[i].first = u;
  }
  v[0].second = r;
  cout << r << " ";
  for (int i = 1; i < n; i++) {
    double y = r;
    for (int j = 0; j < i; j++) {
      if (v[j].first >= v[i].first - (2 * r)) {
        y = max(y,
                v[j].second + sqrt((4 * r * r) - ((v[i].first - v[j].first) *
                                                  (v[i].first - v[j].first))));
      }
    }
    v[i].second = y;
    cout << setprecision(19) << fixed << v[i].second << " ";
  }
  return 0;
}
