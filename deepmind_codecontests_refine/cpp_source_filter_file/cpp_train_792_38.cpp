#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  char a[101][101];
  int b[101][101];
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      char temp;
      scanf("%c", &temp);
      a[i][j] = temp;
      b[i][j] = 1;
      if (a[i][j] == '\n') {
        --j;
      }
    }
  }
  for (int i = 0; i < n; ++i) {
    map<char, int> temp2;
    for (int j = 0; j < m; ++j) {
      temp2[a[i][j]]++;
    }
    for (int j = 0; j < m; ++j) {
      if (temp2[a[i][j]] != 1) b[i][j] = 0;
    }
  }
  for (int i = 0; i < n; ++i) {
    map<char, int> temp2;
    for (int j = 0; j < m; ++j) {
      temp2[a[j][i]]++;
    }
    for (int j = 0; j < m; ++j) {
      if (temp2[a[j][i]] != 1) b[j][i] = 0;
    }
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (b[i][j] == 1) printf("%c", a[i][j]);
    }
  }
  return 0;
}
