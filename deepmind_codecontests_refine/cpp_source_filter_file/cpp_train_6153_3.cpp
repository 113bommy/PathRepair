#include <bits/stdc++.h>
using namespace std;
int main() {
  int n = 0, d = 0, m = 0;
  cin >> n >> d;
  cin >> m;
  int xi = 0;
  int yi = 0;
  vector<pair<int, int> > posithions(m);
  for (int i = 0; i < m; ++i) {
    cin >> posithions[i].first >> posithions[i].second;
    xi = posithions[i].first;
    yi = posithions[i].second;
    if (yi - xi + d < 0) {
      cout << "NO" << endl;
    } else if (yi - xi - d > 0) {
      cout << "NO" << endl;
    } else if (yi - xi + d < 0) {
      cout << "NO" << endl;
    } else if (xi + yi + d - 2 * n > 0) {
      cout << "NO" << endl;
    } else {
      cout << "YES" << endl;
    }
  }
  cout << endl;
}
