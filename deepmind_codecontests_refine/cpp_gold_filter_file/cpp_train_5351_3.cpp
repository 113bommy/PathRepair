#include <bits/stdc++.h>
using namespace std;
int main() {
  int column, row;
  cin >> row >> column;
  string x[row];
  set<int> fori;
  set<int> forj;
  for (int i = 0; i < row; i++) {
    cin >> x[i];
    for (int j = 0; j < x[i].size(); j++) {
      if (x[i][j] == 'S') {
        fori.insert(i);
        forj.insert(j);
      }
    }
  }
  cout << row * column - fori.size() * forj.size();
  return 0;
}
