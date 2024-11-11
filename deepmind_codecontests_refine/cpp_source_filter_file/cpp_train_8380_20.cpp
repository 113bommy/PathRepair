#include <bits/stdc++.h>
using namespace std;
int x, y, x0, y129, ans[1000], sum;
bool used[1000][1000];
string s;
int main() {
  ios_base::sync_with_stdio(0);
  cin >> x >> y >> x0 >> y129;
  cin >> s;
  swap(x, y);
  swap(x0, y129);
  used[x0][y129] = 1;
  ans[0] = 1;
  for (int i = 0; i < s.size() - 1; i++) {
    if (s[i] == 'L')
      x0 = max(1, x0 - 1);
    else if (s[i] == 'R')
      x0 = min(x, x0 + 1);
    else if (s[i] == 'U')
      y129 = max(1, y129 - 1);
    else if (s[i] == 'D')
      y129 = min(y, y129 + 1);
    if (!used[x0][y129]) ans[i + 1] = 1;
    used[x0][y129] = 1;
  }
  for (int i = 1; i <= x; i++)
    for (int j = 1; j <= y; j++)
      if (used[i][j]) sum++;
  for (int i = 0; i < s.size(); i++) cout << ans[i] << " ";
  cout << sum;
  return 0;
}
