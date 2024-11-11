#include <bits/stdc++.h>
using namespace std;
int result(const vector<string>& V) {
  int m = 1000;
  for (int i = 0; i < (1 << 8); ++i) {
    for (int j = 0; j < (1 << 8); ++j) {
      vector<string> cur(8, string(8, 'W'));
      int bits = 0;
      for (int x = 0; x < 8; ++x) {
        if (((1 << x) & i) == 0) continue;
        ++bits;
        for (int k = 0; k < 8; ++k) {
          cur[x][k] = 'B';
        }
      }
      for (int y = 0; y < 8; ++y) {
        if (((1 << y) & j) == 0) continue;
        ++bits;
        for (int k = 0; k < 8; ++k) {
          cur[k][y] = 'B';
        }
      }
      if (cur == V) m = min(m, bits);
    }
  }
  return m;
}
int main() {
  vector<string> V;
  for (int i = 0; i < 8; ++i) {
    string s;
    cin >> s;
    V.push_back(s);
  }
  cout << result(V) << endl;
  return 0;
}
