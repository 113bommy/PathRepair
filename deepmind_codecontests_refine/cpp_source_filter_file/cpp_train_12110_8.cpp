#include <bits/stdc++.h>
using namespace std;
int main() {
  short arr[101][101];
  int n, m;
  string s;
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; ++i) {
    cin >> s;
    for (int j = 0; j < m; ++j) arr[i][j] = s[j] - '0';
  }
  short marks[101];
  int g;
  for (int i = 0; i < m; ++i) {
    g = arr[0][i];
    for (int j = 1; j < n; ++ ++j)
      if (arr[j][i] > g) g = arr[j][i];
    marks[i] = g;
  }
  int res = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (arr[i][j] == marks[j]) {
        ++res;
        break;
      }
    }
  }
  printf("%d", res);
  return 0;
}
