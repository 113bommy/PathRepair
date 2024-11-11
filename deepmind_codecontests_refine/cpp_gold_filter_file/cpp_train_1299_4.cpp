#include <bits/stdc++.h>
using namespace std;
int main() {
  long long x, y, t = 0;
  cin >> y >> x;
  char a[x][y];
  vector<int> row(y, 0), col(x, 0);
  for (int j = 0; j < y; j++) {
    for (int i = 0; i < x; i++) {
      cin >> a[i][j];
      if (a[i][j] == '*') {
        row[j]++;
        col[i]++;
      }
    }
  }
  for (int j = 0; j < y; j++) {
    for (int i = 0; i < x; i++) {
      if (a[i][j] == '*') {
        t += (row[j] - 1) * (col[i] - 1);
      }
    }
  }
  cout << t;
  return 0;
}
