#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  vector<pair<int, int>> a;
  int x, y;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> x >> y;
    a.push_back(make_pair(x, y));
  }
  sort(a.begin(), a.end());
  int f = -1;
  for (int i = 0; i < n; i++) {
    if (f <= a[i].second)
      f = a[i].second;
    else
      f = a[i].first;
  }
  cout << f;
  return 0;
}
