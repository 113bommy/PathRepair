#include <bits/stdc++.h>
using namespace std;
int main(int argc, char* argv[]) {
  int w, h;
  string line;
  getline(cin, line);
  sscanf(line.c_str(), "%d %d", &w, &h);
  vector<string> field;
  for (int _n = h, i = 0; i < _n; ++i) {
    getline(cin, line);
    field.push_back(line);
  }
  vector<string> field_(w, string(h, ' '));
  for (int _n = h, i = 0; i < _n; ++i) {
    for (int _n = w, j = 0; j < _n; ++j) {
      field_[j][h - i] = field[i][j];
    }
  }
  for (int _n = w, i = 0; i < _n; ++i) {
    for (int _n = h / 2, j = 0; j < _n; ++j) {
      swap(field_[i][j], field_[i][h - 1 - j]);
    }
  }
  vector<string> final(w * 2, string(h * 2, ' '));
  for (int _n = w * 2, i = 0; i < _n; ++i) {
    for (int _n = h * 2, j = 0; j < _n; ++j) {
      final[i][j] = field_[i / 2][j / 2];
    }
  }
  for (int _n = w * 2, i = 0; i < _n; ++i) {
    cout << final[i] << endl;
  }
  int Int;
  std::cin >> Int;
}
