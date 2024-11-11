#include <bits/stdc++.h>
using namespace std;
int readin() {
  int x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}
int le[505];
int con[3];
string a[500];
int main() {
  int i, j;
  int t = readin();
  while (t--) {
    int xb = 0;
    memset(con, 0, sizeof(con));
    int n = readin();
    int flg = 0;
    for (i = 1; i <= n; i++) {
      cin >> a[i];
      int len = a[i].length();
      if (len % 2 == 1) {
        flg = 1;
      }
      le[++xb] = len;
      for (j = 0; j <= len - 1; j++) {
        if (a[i][j] == '0') {
          con[0]++;
        }
        if (a[i][j] == '1') {
          con[1]++;
        }
      }
    }
    if (flg == 1) {
      cout << n << endl;
      continue;
    }
    if (con[1] % 2 == 0 || con[0] % 2 == 0) {
      cout << n - 1 << endl;
    } else {
      cout << n << endl;
    }
  }
}
