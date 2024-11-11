#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == '2') {
      cnt++;
    }
  }
  if (cnt == 0) {
    cout << "YES" << endl;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (i == j) {
          cout << 'X';
        } else {
          cout << '=';
        }
      }
      cout << endl;
    }
    return;
  }
  if (cnt < 3) {
    cout << "NO" << endl;
    return;
  }
  char arr[n][n];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      arr[i][j] = '0';
    }
  }
  cout << "YES" << endl;
  for (int i = 0; i < n; i++) {
    int check = 0;
    for (int j = 0; j < n; j++) {
      if (i == j) {
        arr[i][j] = 'X';
      } else if (s[i] == '1') {
        arr[i][j] = '=';
        arr[j][i] = '=';
      } else {
        if (arr[i][j] == '0') {
          if (s[j] == '2' && check == 0) {
            arr[i][j] = '+';
            arr[j][i] = '-';
            check = 1;
          } else {
            arr[i][j] = '-';
            arr[j][i] = '+';
          }
        }
      }
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cout << arr[i][j];
    }
    cout << endl;
  }
}
int main() {
  int test;
  cin >> test;
  while (test--) {
    solve();
  }
}
