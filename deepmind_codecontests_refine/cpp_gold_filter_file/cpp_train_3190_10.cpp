#include <bits/stdc++.h>
using namespace std;
const int sz = 9;
const int lsz = 3;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  char m[sz][sz];
  for (int i = 0; i < sz; ++i)
    for (int j = 0; j < sz; ++j) cin >> m[i][j];
  int a, b;
  cin >> a >> b;
  a--;
  b--;
  int x = a % lsz, y = b % lsz;
  bool full = true;
  for (int i = x * lsz; i < x * lsz + lsz; i++) {
    for (int j = y * lsz; j < y * lsz + lsz; j++) {
      if (m[i][j] == '.') {
        full = false;
        m[i][j] = '!';
      }
    }
  }
  if (full) {
    for (int i = 0; i < sz; ++i) {
      for (int j = 0; j < sz; ++j) {
        if (m[i][j] == '.') m[i][j] = '!';
      }
    }
  }
  for (int i = 0; i < sz; ++i) {
    if (i % lsz == 0 && i != 0) cout << "\n";
    for (int j = 0; j < sz; ++j) {
      if (j % lsz == 0 && j != 0) cout << " ";
      cout << m[i][j];
    }
    cout << "\n";
  }
}
