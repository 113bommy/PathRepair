#include <bits/stdc++.h>
using namespace std;
int main() {
  vector<pair<int, int>> v;
  int x[3];
  int y[3];
  for (int i = 0; i < 3; i++) {
    cin >> x[i] >> y[i];
    v.push_back(make_pair(x[i], y[i]));
  }
  sort(v.begin(), v.end());
  sort(x, x + 3);
  sort(y, y + 3);
  cout << x[2] - x[0] + y[2] - x[0] + 1 << "\n";
  for (int i = x[0]; i < x[1]; i++) {
    cout << i << " " << v[0].second << "\n";
  }
  for (int i = x[1] + 1; i <= x[2]; i++) {
    cout << i << " " << v[2].second << "\n";
  }
  for (int i = y[0]; i <= y[2]; i++) {
    cout << v[1].first << " " << i << "\n";
  }
  return 0;
}
