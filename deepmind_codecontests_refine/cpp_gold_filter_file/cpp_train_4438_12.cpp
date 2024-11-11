#include <bits/stdc++.h>
using namespace std;
string s[90000];
int n;
map<int, int> w[10];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> s[i];
    for (int j = 0; j < 9; j++) {
      int x = 0;
      for (int c = j; c < 9; c++) {
        x = x * 10 + s[i][c] - '0';
        if (w[c - j][x] == 0) {
          w[c - j][x] = i;
        } else if (w[c - j][x] != i) {
          w[c - j][x] = -1;
        }
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    int ans = 9, L = 0, R = 0;
    for (int j = 0; j < 9; j++) {
      int x = 0;
      for (int c = j; c < 9; c++) {
        x = x * 10 + s[i][c] - '0';
        if (w[c - j][x] == i) {
          if (ans > c - j) {
            ans = c - j;
            L = j;
            R = c;
          }
        }
      }
    }
    for (int j = L; j <= R; j++) {
      cout << s[i][j];
    }
    cout << "\n";
  }
}
