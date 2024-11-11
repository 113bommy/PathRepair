#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  char img[200][200];
  int state[200][200] = {};
  for (int i = 0; i < n; i++) scanf("%s", img[i]);
  int rs = 0;
  for (int i = n - 1; i >= 0; i--)
    for (int j = n - 1; j >= 0; j--) {
      int value;
      if (img[i][j] == 'B')
        value = (1 - state[i][j]);
      else
        value = -1 - state[i][j];
      if (value != 0) {
        rs++;
        for (int k = 0; k <= i; k++) {
          for (int l = 0; l <= j; l++) state[k][l] += value;
        }
      }
    }
  cout << rs;
  return 0;
}
