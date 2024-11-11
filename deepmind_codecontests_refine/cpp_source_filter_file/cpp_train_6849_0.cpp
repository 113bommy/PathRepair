#include <bits/stdc++.h>
using namespace std;
int main() {
  int h, w, k;
  cin >> h >> w >> k;
  vector<string> s(h);
  for (auto &e : s) cin >> e;
  vector<vector<int>> r(h, vector<int>(w));
  for (int i = 0, k = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      if (s[i][j] == '#') {
        k++;
        r[i][j] = k;
      }
    }
  }
  for (int i = 0; i < h; i++) {
    for (int j = 1; j < w; j++) {
      if (r[i][j] == 0) r[i][j] = r[i][j - 1];
    }
  }
  for (int i = 0; i < h; i++) {
    for (int j = w - 1; j >= 0; j--) {
      if (r[i][j] == 0) r[i][j] = r[i][j + 1];
    }
  }
  for (int i = 1; i < h; i++) {
    for (int j = 0; j < w; j++) {
      if (r[i][j] == 0) r[i][j] = r[i - 1][j];
    }
  }
  for (int i = h - 1; i >= 0; i--) {
    for (int j = 0; j < w; j++) {
      if (r[i][j] == 0) r[i][j] = r[i + 1][j];
    }
  }
  for (const auto &ri : r) {
    for (const auto &rij : ri) cout << rij << ' ';
    cout << endl;
  }
}
