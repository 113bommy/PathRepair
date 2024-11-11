#include <bits/stdc++.h>
using namespace std;
int main() {
  string s, ss;
  cin >> s;
  ss = s + s;
  int n = s.size();
  int* letters[26][26];
  int counter[26] = {};
  for (int i = 0; i < 26; ++i) {
    for (int j = 0; j < 26; ++j) {
      letters[i][j] = new int[n];
    }
  }
  for (int i = 0; i < n; ++i) {
    int c1 = s.at(i) - 'a';
    counter[c1] += 1;
    for (int j = 0; j < n; ++j) {
      int c2 = ss.at(j + i) - 'a';
      letters[c1][c2][j] += 1;
    }
  }
  vector<vector<int>> conflicts(26);
  vector<vector<int>> pair_counts(26);
  for (int i = 0; i < 26; ++i) {
    conflicts[i].resize(n);
    pair_counts[i].resize(n);
  }
  double count = 0;
  for (int i = 0; i < 26; ++i) {
    for (int j = 0; j < 26; ++j) {
      for (int k = 0; k < n; ++k) {
        int val = letters[i][j][k];
        if (val > 0) {
          pair_counts[i][k] += val;
          if (val > 1) {
            conflicts[i][k] += val;
          }
        }
      }
    }
  }
  for (int i = 0; i < 26; ++i) {
    if (counter[i]) {
      double max_noconflict = -1;
      for (int j = 0; j < n; ++j) {
        if (conflicts[i][j] == 0) {
          max_noconflict = 1;
          break;
        }
        max_noconflict = max(max_noconflict,
                             1.0 - double(conflicts[i][j]) / pair_counts[i][j]);
      }
      count += max_noconflict * counter[i];
    }
  }
  cout.precision(6);
  cout << fixed << count / n << endl;
  for (int i = 0; i < 26; ++i) {
    for (int j = 0; j < 26; ++j) {
      delete[] letters[i][j];
    }
  }
  return 0;
}
