#include <bits/stdc++.h>
using namespace std;
int arr[100100];
int marr[100100][3];
int n, m;
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < 3; j++) {
      scanf("%d", &marr[i][j]);
    }
  }
  for (int i = 0; i < m; i++) {
    int one = 0, two = 0, th = 0;
    for (int j = 0; j < 3; j++) {
      if (arr[marr[i][j]] != 0) {
        if (arr[marr[i][j]] == 1)
          one = 1;
        else if (arr[marr[i][j]] == 2)
          two = 2;
        else
          th = 3;
      }
    }
    for (int j = 0; j < 3; j++) {
      if (arr[marr[i][j]] == 0) {
        if (one == 0) {
          arr[marr[i][j]] = 1;
          one = 1;
        } else if (two == 0) {
          arr[marr[i][j]] = 2;
          two = 2;
        } else if (th == 0) {
          arr[marr[i][j]] = 3;
          th = 3;
        }
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    printf("%d ", arr[i]);
  }
}
