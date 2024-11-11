#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  int miX = 100, miY = 100, maX = 0, maY = 0, c = 0;
  char ch;
  cin >> n >> m;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> ch;
      if (ch == 'B') {
        miX = min(i, miX);
        miY = min(j, miY);
        maX = max(i, maX);
        maY = max(j, maY);
        ++c;
      }
    }
  }
  if (c == 0) return cout << "1\n", 0;
  maX = maX - miX + 1;
  maY = maY - miY + 1;
  int ma = max(maX, maY);
  if (ma > n || ma > m) return cout << "-1\n", 0;
  cout << ma * ma - c << endl;
  return 0;
}
