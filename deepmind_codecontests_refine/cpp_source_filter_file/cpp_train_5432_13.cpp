#include <bits/stdc++.h>
using namespace std;
const int maxn = 55, mod = 1e9 + 7;
const long long inf = 1e18;
bool ans[maxn][maxn];
int n;
bool ask(int x, int y, int xx, int yy) {
  cout << "? " << x + 1 << " " << y + 1 << " " << xx + 1 << " " << yy + 1
       << endl;
  bool ans;
  cin >> ans;
  return ans;
}
void upd(int x, int y) {
  if (x == 0 && y == 0) return;
  if (x == n - 1 && y == n - 1) return;
  if (x >= 1 && y >= 1)
    ans[x][y] = ans[x - 1][y - 1] ^ 1 ^ ask(x - 1, y - 1, x, y);
  else if (x >= 2)
    ans[x][y] = ans[x - 2][y] ^ 1 ^ ask(x - 2, y, x, y);
  else if (y >= 2)
    ans[x][y] = ans[x][y - 2] ^ 1 ^ ask(x, y - 2, x, y);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie();
  cin >> n;
  ans[0][0] = 1;
  for (int i = 2; i < n; i++) upd(0, i);
  for (int i = 1; i < n; i++) upd(1, i);
  ans[1][0] = ans[1][2] ^ 1 ^ ask(1, 0, 1, 2);
  for (int i = 2; i < n; i++)
    for (int j = 0; j < n; j++) upd(i, j);
  vector<pair<int, int> > v;
  pair<int, int> now = {0, 0};
  bool is = 0;
  while (now.first < n && now.second < n) {
    v.push_back(now);
    if (is)
      now.first++;
    else
      now.second++;
    is ^= 1;
  }
  for (int i = 0; i < int((v).size()) - 3; i++) {
    bool num = 0;
    for (int j = i; j < i + 4; j++) {
      num ^= ans[v[j].first][v[j].second];
    }
    if (num == 0) {
      if (ask(v[i].first, v[i].second, v[i + 3].first, v[i + 3].second) ^ 1 ^
          ans[v[i].first][v[i].second] ^ ans[v[i + 3].first][v[i + 3].second]) {
        for (int j = 0; j < n; j++) {
          for (int k = 0; k < n; k++) {
            if ((j + k) & 1) ans[j][k] ^= 1;
          }
        }
      }
      break;
    }
  }
  cout << "!" << endl;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) cout << ans[i][j] << " ";
    cout << "\n";
  }
  return 0;
}
