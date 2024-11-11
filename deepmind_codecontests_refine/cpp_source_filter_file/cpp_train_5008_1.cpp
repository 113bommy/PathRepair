#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, x1, x2, y, j, min = INT_MAX;
  vector<int> vw, hw;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> x1;
    vw.push_back(x1);
  }
  sort(vw.begin(), vw.end());
  vw.push_back(1000000000);
  for (int i = 0; i < m; i++) {
    cin >> x1 >> x2 >> y;
    if (x1 == 1 && x2 >= vw.front()) hw.push_back(x2);
  }
  sort(hw.begin(), hw.end());
  j = 0;
  for (int i = 0; i < vw.size(); i++) {
    if (i >= min) break;
    while (j < hw.size() && vw[i] > hw[j]) j++;
    if (min > i + hw.size() - 1 - j) min = i + hw.size() - 1 - j;
  }
  cout << min;
  return 0;
}
