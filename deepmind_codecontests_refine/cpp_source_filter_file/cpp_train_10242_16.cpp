#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
  int a[5][5];
  for (long long i = 0; i < 5; i++)
    for (long long j = 0; j < 5; j++) a[i][j] = 1;
  int op[5][5];
  op[0][0] = 0;
  op[0][1] = 0;
  op[0][2] = 0;
  op[0][3] = 0;
  op[0][4] = 0;
  op[4][0] = 0;
  op[4][1] = 0;
  op[4][2] = 0;
  op[4][3] = 0;
  op[4][4] = 0;
  op[1][0] = 0;
  op[2][0] = 0;
  op[3][0] = 0;
  op[1][4] = 0;
  op[2][4] = 0;
  op[3][4] = 0;
  for (long long i = 1; i < 4; i++) {
    for (long long j = 1; j < 4; j++) {
      cin >> op[i][j];
    }
  }
  for (long long i = 1; i < 4; i++) {
    for (long long j = 1; j < 4; j++) {
      if ((op[i][j] + op[i - 1][j] + op[i][j + 1] + op[i + 1][j] +
           op[i][j - 1]) %
              2 ==
          0) {
      } else {
        a[i][j] = 0;
      }
    }
  }
  for (long long i = 1; i < 4; i++) {
    for (long long j = 1; j < 4; j++) {
      cout << a[i][j] << " ";
    }
    cout << endl;
  }
  return 0;
}
