#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, c = 0;
  cin >> n;
  vector<pair<int, int>> v(n);
  vector<vector<bool>> w(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i].first >> v[i].second;
  }
  for (int i = 0; i < n; i++) {
    w[i].resize(4);
    for (int j = 0; j < n; j++) {
      if (v[j].first == v[i].first && v[j].second > v[i].second)
        w[i][0] = true;
      else if (v[j].first == v[i].first && v[j].second < v[i].second)
        w[i][1] = true;
      else if (v[j].second == v[i].second && v[j].first > v[i].first)
        w[i][2] = true;
      else if (v[j].second == v[i].second && v[j].first < v[i].first)
        w[i][3] = true;
    }
  }
  for (int i = 0; i < n; i++) {
    if (w[i][0] && w[i][1] && w[i][2] && w[i][3]) c++;
  }
  cout << c << endl;
  return 0;
}
