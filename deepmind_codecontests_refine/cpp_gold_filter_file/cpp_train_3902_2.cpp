#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ;
  int n, m;
  cin >> n >> m;
  bool l = true, r = false;
  for (int i = 1; i <= n; ++i) {
    if (i % 2) {
      for (int j = 0; j < m; ++j) cout << '#';
      cout << '\n';
    } else if (l) {
      for (int j = 0; j < m - 1; ++j) cout << '.';
      cout << '#' << '\n';
      l = false;
      r = true;
    } else {
      cout << '#';
      for (int j = 0; j < m - 1; ++j) cout << '.';
      cout << '\n';
      l = true;
      r = false;
    }
  }
}
