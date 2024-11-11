#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  char c[n][m];
  int i, j, k, l, t;
  int temp1, temp2, temp3, temp4;
  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++) {
      cin >> c[i][j];
      if (c[i][j] == 'S') {
        temp1 = i;
        temp2 = j;
      }
      if (c[i][j] == 'E') {
        temp3 = i;
        temp4 = j;
      }
    }
  }
  int v = temp1, w = temp2;
  string s;
  cin >> s;
  int count = 0, flag;
  for (i = 0; i < 4; i++) {
    for (j = 0; j < 4; j++) {
      for (k = 0; k < 4; k++) {
        for (l = 0; l < 4; l++) {
          flag = 0;
          v = temp1;
          w = temp2;
          if (i != j && j != k && k != l && i != k && i != l && j != l) {
            for (t = 0; t < s.length(); t++) {
              if ((s[t] - 48) == i) {
                v++;
                if (v == temp3 && w == temp4) {
                  flag = 1;
                  break;
                }
                if (v >= n) {
                  flag = 0;
                  break;
                }
                if (c[v][w] == '#') {
                  flag = 0;
                  break;
                }
              } else if ((s[t] - 48) == j) {
                v--;
                if (v == temp3 && w == temp4) {
                  flag = 1;
                  break;
                }
                if (v < 0) {
                  flag = 0;
                  break;
                }
                if (c[v][w] == '#') {
                  flag = 0;
                  break;
                }
              } else if ((s[t] - 48) == k) {
                w++;
                if (v == temp3 && w == temp4) {
                  flag = 1;
                  break;
                }
                if (w >= m) {
                  flag = 0;
                  break;
                }
                if (c[v][w] == '#') {
                  flag = 0;
                  break;
                }
              } else if ((s[t] - 48) == l) {
                w--;
                if (v == temp3 && w == temp4) {
                  flag = 1;
                  break;
                }
                if (w < 0) {
                  flag = 0;
                  break;
                }
                if (c[v][w] == '#') {
                  flag = 0;
                  break;
                }
              }
            }
            if (v == temp3 && w == temp4) flag = 1;
            if (flag == 1) count++;
          }
        }
      }
    }
  }
  cout << count;
  return 0;
}
