#include <bits/stdc++.h>
using namespace std;
int a[500][500];
int main() {
  int t = 2, t2 = 1;
  int n;
  cin >> n;
  a[0][0] = 1;
  a[1][0] = 1;
  int cnt = 2;
  int nw = 2;
  for (int i = 0; i < 200; i++) {
    for (int j = 0; j < cnt; j++) {
      a[j][t2] = nw;
      a[t][j] = nw;
      nw++;
    }
    if (nw > n) {
      if (nw - 1 == n) {
        t++;
        t2++;
      }
      break;
    } else {
      t2++;
      t++;
      cnt++;
    }
  }
  cout << t << endl;
  for (int i = 0; i < t; i++) {
    for (int j = 0; j < t2; j++) {
      cout << a[i][j] << " ";
    }
    cout << endl;
  }
  return 0;
}
