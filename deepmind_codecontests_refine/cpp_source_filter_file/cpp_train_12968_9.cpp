#include <bits/stdc++.h>
using namespace std;
int main(int argc, const char* argv[]) {
  vector<string> input;
  int n_row, n_col;
  cin >> n_row >> n_col;
  cin.ignore();
  for (int i = 0; i < n_row; i++) {
    string temp;
    getline(cin, temp);
    input.push_back(temp);
  }
  vector<bool> cols(n_col, false);
  vector<bool> rows(n_row, false);
  for (int i = 0; i < n_row; i++) {
    for (int j = 0; j < n_col; j++) {
      if (input[i][j] == 'X') {
        cols[j] = true;
        rows[i] = true;
      }
    }
  }
  bool rect = true;
  for (int i = 0; i < n_row; i++) {
    for (int j = 0; j < n_col; j++) {
      if (input[i][j] == '.' && (cols[i] && rows[j])) rect = false;
    }
  }
  if (rect)
    cout << "YES";
  else
    cout << "NO";
  cout << endl;
}
