#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  string s;
  int a;
  int x = 0, y = n + 1;
  for (int i = 0; i < m; i++) {
    cin >> s;
    cin >> s;
    cin >> s;
    if (s[0] == 'r') {
      cin >> s;
      cin >> a;
      if (a > x) x = a;
    } else {
      cin >> s;
      cin >> a;
      if (a < y) y = a;
    }
  }
  if (y - x == 1 || x == n || y == 1)
    cout << -1;
  else
    cout << y - x - 1;
  return 0;
}
