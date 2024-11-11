#include <bits/stdc++.h>
using namespace std;
int main() {
  int x, y, n;
  cin >> n;
  vector<int> v[100010], barg;
  for (int i = 0; i < n - 1; i++) {
    cin >> x >> y;
    v[x].push_back(y);
    v[y].push_back(x);
  }
  for (int i = 1; i <= n; i++) {
    if (v[i].size() == 2) {
      cout << "NO";
      return 0;
    }
  }
  cout << "YES";
}
