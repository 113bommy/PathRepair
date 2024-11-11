#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argarr[]) {
  int r, c;
  cin >> r >> c;
  int arr[r][c];
  vector<pair<int, int> > barr;
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      char ch;
      cin >> ch;
      arr[i][j] = ch;
      if (ch == 'S') barr.push_back(pair<int, int>(i, j));
    }
  }
  set<int> row, col;
  for (int i = 0; i < barr.size(); i++) {
    row.insert(barr[i].first);
    col.insert(barr[i].second);
  }
  int count = 0;
  for (int i = 0; i < r; i++) {
    if (row.find(i) == row.end()) {
      for (int j = 0; j < c; j++) {
        arr[i][j] = 'e';
        count++;
      }
    }
  }
  for (int i = 0; i < c; i++) {
    if (col.find(i) == col.end()) {
      for (int j = 0; j < r; j++) {
        if (arr[j][i] != 'e') {
          arr[j][i] = 'e';
          count++;
        }
      }
    }
  }
  cout << count << endl;
  return 0;
}
