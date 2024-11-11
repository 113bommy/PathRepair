#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  multiset<int> s[1003][2];
  int x;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> x;
      s[i + j][0].insert(x);
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> x;
      s[i + j][1].insert(x);
    }
  }
  for (int i = 2; i <= (n + m); i++) {
    if (s[i][0] != s[i][1]) {
      cout << "NO" << '\n';
      return 0;
    }
  }
  cout << "YES" << '\n';
  return 0;
}
