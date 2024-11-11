#include <bits/stdc++.h>
using namespace std;
bool go(vector<vector<int> > &v, int row, int col) {
  set<int> sr[2];
  for (int i = 0; i < row; i++)
    for (int j = 0; j < col; j++)
      if (v[i][j] != 0) sr[i % 2].insert(v[i][j]);
  if ((int)sr[0].size() == 0 && (int)sr[1].size() == 0) {
    for (int i = 0; i < row; i++)
      for (int j = 0; j < col; j++) {
        if (i % 2 == 0 && j % 2 == 0)
          v[i][j] = 1;
        else if (i % 2 == 0)
          v[i][j] = 2;
        else if (j % 2 == 0)
          v[i][j] = 3;
        else
          v[i][j] = 4;
      }
    return true;
  }
  if ((int)sr[0].size() > 2 || (int)sr[1].size() > 2) return false;
  for (int i : sr[0])
    for (int j : sr[1])
      if (i == j) return false;
  bool b[5];
  memset(b, true, sizeof(b));
  for (int i : sr[0]) b[i] = false;
  for (int i : sr[1]) b[i] = false;
  while ((int)sr[0].size() < 2) {
    int num = 1;
    while (!b[num]) num++;
    sr[0].insert(num);
    b[num] = false;
  }
  while ((int)sr[1].size() < 2) {
    int num = 1;
    while (!b[num]) num++;
    sr[1].insert(num);
    b[num] = false;
  }
  int r[2][2];
  int p = 0;
  for (int i : sr[0]) r[0][p++] = i;
  p = 0;
  for (int i : sr[1]) r[1][p++] = i;
  for (int i = 0; i < row; i++)
    for (int j = 0; j < col; j++) {
      if (v[i][j] != 0) {
        int j1 = j - 1;
        while (j1 >= 0) {
          if (v[i][j1] == v[i][j1 + 1]) return false;
          if (v[i][j1 + 1] == r[i % 2][0])
            v[i][j1] = r[i % 2][1];
          else
            v[i][j1] = r[i % 2][0];
          j1--;
        }
        int j2 = j + 1;
        while (j2 < col) {
          if (v[i][j2] == v[i][j2 - 1]) return false;
          if (v[i][j2 - 1] == r[i % 2][0])
            v[i][j2] = r[i % 2][1];
          else
            v[i][j2] = r[i % 2][0];
          j2++;
        }
        break;
      } else if (j == col - 1) {
        for (int j = 0; j < col; j++) v[i][j] = r[i % 2][j % 2];
      }
    }
  return true;
}
int main() {
  int row, col;
  cin >> row >> col;
  int table[row][col];
  for (int i = 0; i < row; i++) {
    string s;
    cin >> s;
    for (int j = 0; j < col; j++) table[i][j] = s[j] - '0';
  }
  vector<vector<int> > v1, v2;
  for (int i = 0; i < row; i++) v1.push_back(vector<int>(0));
  for (int j = 0; j < col; j++) v2.push_back(vector<int>(0));
  for (int i = 0; i < row; i++)
    for (int j = 0; j < col; j++) v1[i].push_back(table[i][j]);
  for (int j = 0; j < col; j++)
    for (int i = 0; i < row; i++) v2[j].push_back(table[i][j]);
  if (go(v1, row, col)) {
    for (int i = 0; i < row; i++) {
      for (int j = 0; j < col; j++) cout << v1[i][j];
      cout << endl;
    }
  } else if (go(v2, col, row)) {
    for (int i = 0; i < row; i++) {
      for (int j = 0; j < col; j++) cout << v2[j][i];
      cout << endl;
    }
  } else
    cout << 0;
  return 0;
}
