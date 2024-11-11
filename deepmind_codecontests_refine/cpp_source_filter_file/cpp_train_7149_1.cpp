#include <bits/stdc++.h>
using namespace std;
int main() {
  string line;
  getline(cin, line);
  if (line.size() <= 2) {
    cout << "NO" << endl;
    return 0;
  }
  vector<char> cols(line.size());
  for (int i = 0; i < line.size(); i++) {
    if (line[i] != '.') {
      char mask = 0;
      if (line[i] == 'B') {
        mask = 1;
      } else if (line[i] == 'C') {
        mask = 2;
      } else {
        mask = 4;
      }
      cols[i] |= mask;
      if (i != 0) {
        cols[i - 1] |= mask;
      }
      if (i != line.size() - 1) {
        cols[i + 1] |= mask;
      }
    }
  }
  for (auto ch : cols) {
    if (ch == 7) {
      cout << int(ch) << endl;
      return 0;
    }
  }
  cout << "NO" << endl;
}
