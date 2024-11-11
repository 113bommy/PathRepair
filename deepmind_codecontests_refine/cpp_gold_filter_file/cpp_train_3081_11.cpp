#include <bits/stdc++.h>
using namespace std;
const int N = 8;
char arr[8][8];
bool if_all_black() {
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      if (arr[i][j] != 'B') return false;
    }
  }
  return true;
}
int column_black() {
  int cnt = 0;
  for (int i = 0; i < N; ++i) {
    bool bol = true;
    for (int j = 0; j < N; ++j) {
      if (arr[i][j] != 'B') bol = false;
    }
    if (bol == true) cnt++;
  }
  return cnt;
}
int row_black() {
  int cnt = 0;
  for (int j = 0; j < N; ++j) {
    bool bol = true;
    for (int i = 0; i < N; ++i) {
      if (arr[i][j] != 'B') bol = false;
    }
    if (bol == true) cnt++;
  }
  return cnt;
}
int main() {
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      cin >> arr[i][j];
    }
  }
  if (if_all_black())
    cout << "8";
  else
    cout << row_black() + column_black();
  return 0;
}
