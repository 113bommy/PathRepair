#include <bits/stdc++.h>
using namespace std;
int n, m, x, y;
string str;
bool visited[550][550];
int main() {
  cin >> n >> m >> x >> y;
  cin >> str;
  int cnt = 0;
  for (int i = 0; str[i]; i++) {
    if (!visited[x][y]) {
      cout << "1 ";
      cnt++;
    } else {
      cout << "0 ";
    }
    visited[x][y] = true;
    if (str[i] == 'U' && y > 1) y--;
    if (str[i] == 'D' && y < m) y++;
    if (str[i] == 'L' && x > 1) x--;
    if (str[i] == 'R' && x < n) x++;
  }
  cout << n * m - cnt << "\n";
  return 0;
}
