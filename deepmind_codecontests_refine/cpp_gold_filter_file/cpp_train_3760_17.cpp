#include <bits/stdc++.h>
#pragma GCC optimize("-O2")
using namespace std;
const int LIM = 1e5 + 5, MOD = 1e9 + 7;
int t, n, m, k, x, y;
string s;
int main() {
  srand(time(0));
  cin >> n;
  bool dir = 0, ch = 1, prec = 1;
  cout << 0 << " " << 0 << endl;
  cin >> s;
  if (s[0] == 'b') prec = 0;
  int nx = 0, ny = 1e9;
  vector<pair<int, int> > black, white;
  if (prec)
    white.push_back(make_pair(0, 0));
  else
    black.push_back(make_pair(0, 0));
  for (int i = 1; i < n; i++) {
    x = (nx + ny) / 2;
    if ((nx + ny) & 1) x++;
    if (i != n - 1)
      cout << x << " " << 0 << endl;
    else
      cout << x << " 1" << endl;
    cin >> s;
    if ((s[0] == 'b') == prec) {
      ch ^= 1;
      ny = x;
    } else
      nx = x;
    if (s[0] != 'b')
      white.push_back(make_pair(x, 0));
    else
      black.push_back(make_pair(x, 0));
  }
  if (black.size() == 0 || black.size() == n) {
    cout << "1 2 2 2" << endl;
  } else {
    if (white[0].first == 0) {
      cout << min(black.back().first, black[0].first) - 1 << " " << 0 << " "
           << min(black.back().first, black[0].first) << " " << 2 + rand()
           << endl;
    } else {
      cout << min(white.back().first, white[0].first) - 1 << " " << 0 << " "
           << min(white.back().first, white[0].first) << " " << 2 + rand()
           << endl;
    }
  }
  return 0;
}
