#include <bits/stdc++.h>
using namespace std;
char game[110][110];
int main() {
  int n, m, k;
  cin >> n >> m >> k;
  vector<int> v;
  int w2 = 0, w1 = 0, f = 0, s = 0;
  for (int i = 0; i < n; i++) {
    int r = 0, g = 0, d = 0;
    for (int j = 0; j < m; j++) {
      cin >> game[i][j];
      if (game[i][j] == 'R')
        r = j + 1;
      else if (game[i][j] == 'G')
        g = j + 1;
      else
        d = 1;
    }
    if (r && g)
      v.push_back(abs(r - g) - 1);
    else if (!r && g && d)
      f = 1;
    else if (r && !g && d)
      s = 1;
  }
  if (v.size())
    for (int idx = 0; idx <= 5; idx++) {
      int x = 0;
      for (int i = 0; i < v.size(); i++) {
        x += (v[i] >> idx);
      }
      if (x % (k + 1)) w1 = 1;
    }
  if (f && s)
    cout << "Draw\n";
  else if (!f)
    cout << "First\n";
  else if (!s)
    cout << "Second\n";
  else if (!w1)
    cout << "Second\n";
  else
    cout << "First\n";
}
