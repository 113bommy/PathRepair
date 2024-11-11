#include <bits/stdc++.h>
using namespace std;
int n;
string s;
vector<vector<char> > g;
int main() {
  cin >> n >> s;
  int maxs = 3, sum = 3, sz = n;
  for (int i = 1; i != n; ++i) {
    if (s[i] == '[') {
      sum += 2;
    } else {
      if (s[i - 1] == '[') {
        sz += 3;
      }
      maxs = max(maxs, sum);
      sum -= 2;
    }
  }
  g.resize(maxs + 1);
  for (int i = 1; i <= maxs; ++i) {
    g[i].resize(sz + 1, ' ');
  }
  int j = 1, curs1 = 1, curs2 = maxs;
  for (int z = 0; z != n; ++z) {
    if (s[z] == '[') {
      g[curs1][j] = '+';
      g[curs2][j] = '+';
      g[curs1][j + 1] = '-';
      g[curs2][j + 1] = '-';
      for (int i = curs1 + 1; i < curs2; ++i) {
        g[i][j] = '|';
      }
      curs1 += 1;
      curs2 -= 1;
      ++j;
    } else {
      if (s[z - 1] == '[') j += 3;
      curs1 -= 1;
      curs2 += 1;
      g[curs1][j] = '+';
      g[curs2][j] = '+';
      g[curs1][j - 1] = '-';
      g[curs2][j - 1] = '-';
      for (int i = curs1 + 1; i < curs2; ++i) {
        g[i][j] = '|';
      }
      ++j;
    }
  }
  for (int i = 1; i <= maxs; ++i) {
    for (int j = 1; j <= sz; ++j) {
      cout << g[i][j];
    }
    if (i != maxs) cout << "\n";
  }
}
