#include <bits/stdc++.h>
using namespace std;
int main() {
  vector<int> v[6];
  int m, a = 0;
  cin >> m;
  for (int i = 1; i <= m; i++) {
    int x, y;
    cin >> x >> y;
    v[x].push_back(y);
    v[y].push_back(x);
  }
  for (int i = 1; i <= 6; i++) {
    if (v[i].size() == 2) a++;
  }
  if (a == m)
    cout << "FAIL" << endl;
  else
    cout << "WIN" << endl;
  return 0;
}
