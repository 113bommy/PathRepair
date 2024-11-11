#include <bits/stdc++.h>
using namespace std;
struct area {
  bool danger;
  char mark;
};
void yes() {
  cout << "YES" << endl;
  exit(0);
};
int main() {
  int n, k, i, j;
  cin >> n >> k;
  area m[2][n];
  string line;
  for (i = 0; i < 2; i++) {
    cin >> line;
    for (j = 0; j < n; j++) {
      m[i][j].mark = -1;
      m[i][j].danger = (line[j] == 'X');
    }
  }
  queue<int> y;
  queue<int> x;
  y.push(0);
  x.push(0);
  m[0][0].mark = 0;
  while (!y.empty()) {
    i = y.front();
    j = x.front();
    y.pop();
    x.pop();
    if (j == n - 1) yes();
    if (!m[i][j + 1].danger && m[i][j + 1].mark == (-1) &&
        (j + 1) > m[i][j].mark) {
      y.push(i);
      x.push(j + 1);
      m[i][j + 1].mark = m[i][j].mark + 1;
    }
    if (j > 0)
      if (!m[i][j - 1].danger && m[i][j - 1].mark == (-1) &&
          (j - 1) > m[i][j].mark) {
        y.push(i);
        x.push(j - 1);
        m[i][j - 1].mark = m[i][j].mark + 1;
      }
    if (j + k >= n) yes();
    if (!m[1 - i][j + k].danger && m[1 - i][j + k].mark == (-1) &&
        (j + k) > m[i][j].mark) {
      y.push(1 - i);
      x.push(j + k);
      m[1 - i][j + k].mark = m[i][j].mark + 1;
    }
  }
  cout << "NO" << endl;
  return 0;
}
