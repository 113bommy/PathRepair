#include <bits/stdc++.h>
using namespace std;
int n;
char v[101][101];
int oo;
int ro;
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      cin >> v[i][j];
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (v[i][j] == 'C') {
        ro++;
      }
    }
    oo = oo + (ro * (ro - 1) / 2);
    ro = 0;
  }
  for (int j = 1; j <= n; j++) {
    for (int i = 1; i <= n; i++) {
      if (v[i][j] == 'C') {
        ro++;
      }
    }
    oo = oo + (ro * (ro - 1) / 2);
    ro = 0;
  }
  cout << oo;
  return 0;
}
