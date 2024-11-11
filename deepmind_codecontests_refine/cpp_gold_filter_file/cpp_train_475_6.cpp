#include <bits/stdc++.h>
using namespace std;
vector<vector<int> > g;
int f(string s) {
  switch (s[0]) {
    case 'A':
      return 0;
    case 'C':
      return (s[1] == 'h' ? 1 : 2);
    case 'T':
      return 3;
    case 'D':
      return 4;
    case 'S':
      return 5;
    case 'H':
      return 6;
  }
}
int main() {
  int n, a, b, c;
  cin >> n;
  g.resize(7);
  for (int i = 0; i < (int)(n); i++) {
    string a, b;
    cin >> a >> b >> b;
    cerr << f(a) << " " << f(b) << endl;
    g[f(a)].push_back(f(b));
  }
  cin >> a >> b >> c;
  int i[7];
  pair<int, int> ans = make_pair(2100000000, 0);
  for (i[0] = 0; i[0] < 3; i[0]++) {
    for (i[1] = 0; i[1] < 3; i[1]++) {
      for (i[2] = 0; i[2] < 3; i[2]++) {
        for (i[3] = 0; i[3] < 3; i[3]++) {
          for (i[4] = 0; i[4] < 3; i[4]++) {
            for (i[5] = 0; i[5] < 3; i[5]++) {
              for (i[6] = 0; i[6] < 3; i[6]++) {
                int x, y, z, m;
                x = y = z = m = 0;
                for (int i1 = 0; i1 < (int)(7); i1++) {
                  if (i[i1] == 0) {
                    x++;
                  } else if (i[i1] == 1) {
                    y++;
                  } else {
                    z++;
                  }
                  for (int j = 0; j < (int)(g[i1].size()); j++) {
                    if (i[i1] == i[g[i1][j]]) {
                      m++;
                    }
                  }
                }
                if (!x || !y || !z) {
                  continue;
                }
                x = a / x;
                y = b / y;
                z = c / z;
                ans = min(
                    ans, make_pair(max(abs(x - y), max(abs(x - z), abs(y - z))),
                                   -m));
              }
            }
          }
        }
      }
    }
  }
  cout << ans.first << " " << -ans.second;
}
