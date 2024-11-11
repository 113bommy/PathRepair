#include <bits/stdc++.h>
using namespace std;
char b[101];
char a[101][101];
int mark[101];
int main() {
  int n, m, s = 0;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> a[i][j];
      if (a[i][j] > b[j]) {
        b[j] = a[i][j];
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (a[i][j] == b[j]) {
        if (mark[i] == 0) {
          s++;
          mark[i]++;
        }
      }
    }
  }
  cout << s;
}
