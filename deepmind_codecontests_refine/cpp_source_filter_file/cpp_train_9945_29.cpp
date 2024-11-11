#include <bits/stdc++.h>
using namespace std;
vector<string> q[211111];
int q1, q2;
set<vector<string> > was;
int main() {
  ios::sync_with_stdio(false);
  vector<string> s;
  s.resize(2);
  cin >> s[0] >> s[1];
  vector<string> g;
  g.resize(2);
  cin >> g[0] >> g[1];
  was.insert(s);
  q[q1++] = s;
  while (q1 != q2) {
    vector<string> x = q[q2++];
    for (int i = 0; i < 2; i++)
      for (int j = 0; j < 2; j++)
        for (int ii = 0; ii < 2; ii++)
          for (int jj = 0; jj < 2; jj++)
            if (s[i][j] == 'X' && abs(i - ii) + abs(j - jj) == 1) {
              vector<string> e = x;
              swap(e[i][j], e[ii][jj]);
              if (was.find(e) == was.end()) {
                was.insert(e);
                q[q1++] = e;
              }
            }
  }
  if (was.find(g) == was.end())
    cout << "NO\n";
  else
    cout << "YES\n";
  return 0;
}
