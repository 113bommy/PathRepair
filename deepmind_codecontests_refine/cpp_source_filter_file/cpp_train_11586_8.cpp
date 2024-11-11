#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, z;
  bool wing = 0, winr = 0;
  cin >> n >> m >> z;
  char a[n + 5][m + 5];
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) cin >> a[i][j];
  short s[105];
  memset(s, 0, sizeof(s));
  int ans = 0;
  bool r = 0, g = 0;
  for (int i = 0; i < n; i++) {
    bool first = 0, second = 0;
    bool q = 0, w = 0;
    int c = 0;
    for (int j = 0; j < m; j++) {
      if (a[i][j] == 'G' || a[i][j] == 'R') {
        if (a[i][j] == 'G') q = 1, g = 1;
        if (a[i][j] == 'R') w = 1, r = 1;
        if (!first)
          first = 1;
        else
          second = 1;
      } else if (first && !second)
        c++;
    }
    s[i] = c;
  }
  for (int i = 0; i < n; i++) {
    int c = 0;
    bool q = 0, w = 0;
    for (int j = 0; j < m; j++) {
      if (a[i][j] == 'G')
        q = 1;
      else if (a[i][j] == 'R')
        w = 1;
      else
        c++;
    }
    if (q && !w && c)
      wing = 1;
    else if (!q && w && c)
      winr = 1;
  }
  int bits[15];
  memset(bits, 0, sizeof(bits));
  for (int i = 0; i < n; i++) {
    int k = 0;
    while (s[i]) {
      bits[k] += (s[i] % 2);
      s[i] /= 2;
      k++;
    }
  }
  for (int i = 0; i < 15; i++) {
    ans = ans ^ (bits[i] % (z + 1));
  }
  if (!g)
    cout << "Second\n";
  else if (!r && ans)
    cout << "First\n";
  else if (wing && winr)
    cout << "Draw\n";
  else if (wing)
    cout << "First\n";
  else if (winr)
    cout << "Second\n";
  else {
    if (!ans)
      cout << "Second\n";
    else
      cout << "First\n";
  }
}
