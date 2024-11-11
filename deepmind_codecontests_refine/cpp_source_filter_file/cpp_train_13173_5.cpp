#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, d;
  cin >> n >> d;
  char aa[d][n];
  int a[d];
  memset(a, 0, sizeof(a));
  for (int i = 0; i < d; i++) {
    for (int j = 0; j < n; j++) {
      cin >> aa[i][j];
      if (aa[i][j] == '0') a[i] = 1;
    }
  }
  int countt = 0;
  int maxx = 0;
  for (int i = 0; i < d - 1; i++) {
    if (a[i] == 1) {
      countt++;
      if (a[i + 1] == 0) {
        if (maxx <= countt) {
          maxx = countt;
        }
        countt = 0;
      }
    }
  }
  cout << maxx;
  return 0;
}
