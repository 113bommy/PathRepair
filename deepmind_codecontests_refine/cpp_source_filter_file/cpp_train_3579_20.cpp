#include <bits/stdc++.h>
using namespace std;
int a[4], win[360][360];
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
  if (n == 1) {
    printf(a[0] == 0 ? "BitAryo\n" : "BitLGM\n");
    return 0;
  }
  if (n == 3) {
    int x = a[0] ^ a[1] ^ a[2];
    printf(x == 0 ? "BitAryo\n" : "BitLGM\n");
    return 0;
  }
  for (int i = 1; i <= a[0]; ++i) win[i][0] = 1;
  for (int i = 1; i <= a[1]; ++i) win[0][i] = 1;
  for (int i = 1; i <= a[0]; ++i) {
    for (int j = 1; j <= a[1]; ++j) {
      bool is_win = true;
      for (int k = 0; k < i; ++k) is_win &= win[k][j];
      for (int k = 0; k < j; ++k) is_win &= win[i][k];
      int minn = min(a[i], a[j]);
      for (int k = 1; k <= minn; ++k) is_win &= win[i - k][j - k];
      win[i][j] = !is_win;
    }
  }
  printf(win[a[0]][a[1]] == 0 ? "BitAryo\n" : "BitLGM\n");
  return 0;
}
