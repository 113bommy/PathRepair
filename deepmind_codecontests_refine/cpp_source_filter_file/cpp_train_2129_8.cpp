#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  char str[8];
  char mp[256];
  char card[100][4];
  mp['R'] = 0;
  mp['G'] = 1;
  mp['B'] = 2;
  mp['Y'] = 3;
  mp['W'] = 4;
  cin >> n;
  for (int i = 0; i < (int)(n); ++i) {
    cin >> card[i];
  }
  vector<pair<int, int> > h(n);
  int res = 10000;
  for (int hint = 0; hint < (int)(1 << 10); ++hint) {
    for (int i = 0; i < (int)(n); ++i) {
      int j = mp[card[i][0]];
      if (hint & (1 << j))
        h[i].first = j;
      else
        h[i].first = -1;
      j = card[i][1] - '0';
      if (hint & (1 << (5 + j)))
        h[i].second = 5 + j;
      else
        h[i].second = -1;
    }
    bool ok = true;
    for (int i = 0; i < (int)(n); ++i)
      for (int j = (i + 1); j < (int)(n); ++j)
        if (h[i] == h[j] &&
            (card[i][0] != card[j][0] || card[i][1] != card[j][1]))
          ok = false;
    if (ok) {
      int cnt = 0, tmp = hint;
      while (tmp) {
        if (tmp & 1) ++cnt;
        tmp >>= 1;
      }
      if (cnt < res) {
        res = cnt;
      }
    }
  }
  cout << res << endl;
  return 0;
}
