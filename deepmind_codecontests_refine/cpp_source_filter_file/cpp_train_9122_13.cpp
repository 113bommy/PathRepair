#include <bits/stdc++.h>
using namespace std;
vector<pair<int, char>> v[103];
int n, m;
int canwin[101][101][26];
int getans(int x, int y, char let) {
  int &ans = canwin[x][y][let];
  if (ans != -1) return ans;
  ans = 0;
  for (const auto &nb : v[x]) {
    if (nb.second >= let && getans(y, nb.first, nb.second) == 0) {
      ans = 1;
      break;
    }
  }
  return ans;
}
int main() {
  scanf("%d %d", &n, &m);
  memset(canwin, -1, sizeof(canwin));
  while (m--) {
    int x, y;
    char c;
    scanf("%d %d %c", &x, &y, &c);
    v[x].push_back(make_pair(y, c));
  }
  for (int i = 1; i <= n; i++) {
    string s = "";
    for (int j = 1; j <= n; j++) {
      if (getans(i, j, 'a') == 1)
        s += 'A';
      else
        s += 'B';
    }
    cout << s << endl;
  }
  return 0;
}
