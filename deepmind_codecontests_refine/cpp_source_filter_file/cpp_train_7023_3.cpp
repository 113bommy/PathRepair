#include <bits/stdc++.h>
using namespace std;
int done[1005];
char str[105][105];
int main() {
  int r, c, cnt, sol, i, j;
  ios::sync_with_stdio(false);
  cin >> r >> c;
  for (i = 0; i < r; i++) {
    cin >> str[i];
  }
  cnt = 0;
  for (i = 0; i < c; i++) {
    sol = 0;
    for (j = 1; j < r; j++) {
      if (!done[j] && (str[j][i] < str[j - 1][i])) {
        sol = 1;
      }
    }
    if (!sol) {
      for (j = 1; j < r; j++) {
        if (!done[j] && (str[j][i] > str[j][i - 1])) done[j] = 1;
      }
    } else {
      cnt++;
    }
  }
  cout << cnt << endl;
  return 0;
}
