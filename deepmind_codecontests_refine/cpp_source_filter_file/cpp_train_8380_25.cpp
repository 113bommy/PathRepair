#include <bits/stdc++.h>
using namespace std;
int main() {
  int x, y, sx, sy;
  cin >> x >> y >> sx >> sy;
  sx--;
  sy--;
  string s;
  cin >> s;
  int cnt[505][505];
  for (int i = 0; i < x; i++)
    for (int j = 0; j < y; j++) cnt[i][j] = s.size();
  cnt[sx][sy] = 0;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == 'D')
      sx--;
    else if (s[i] == 'U')
      sx++;
    else if (s[i] == 'L')
      sy--;
    else
      sy++;
    sx = min(sx, x - 1);
    sx = max(sx, 0);
    sy = min(sy, y - 1);
    sy = max(sy, 0);
    cnt[sx][sy] = min(cnt[sx][sy], i + 1);
  }
  vector<int> ans(s.size() + 1);
  for (int i = 0; i < x; i++)
    for (int j = 0; j < y; j++) ans[cnt[i][j]]++;
  for (int i = 0; i < s.size() + 1; i++) {
    if (i > 0) cout << " ";
    cout << ans[i];
  }
  cout << "\n";
}
