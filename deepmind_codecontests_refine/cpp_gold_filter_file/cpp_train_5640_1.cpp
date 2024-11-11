#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<vector<int> > v(n + 1);
  for (int i = 0; i < n - 1; i++) {
    int x, y;
    cin >> x >> y;
    v[x].push_back(y);
    v[y].push_back(x);
  }
  int f = 0;
  for (int i = 1; i <= n; i++) {
    if (v[i].size() == 2) {
      f = 1;
      break;
    }
  }
  if (f == 1)
    cout << "NO";
  else
    cout << "YES";
  return 0;
}
