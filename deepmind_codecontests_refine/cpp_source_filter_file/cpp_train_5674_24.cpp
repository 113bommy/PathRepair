#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  int a[100][100];
  int b[100];
  int p(0), t(0), temp;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      cin >> a[i][j];
      if (a[i][j] > p) {
        p = a[i][j];
        t = j;
      }
    }
    b[t]++;
    t = 0;
    p = 0;
  }
  for (int i = 0; i < m; i++) {
    if (b[i] > temp) {
      temp = b[i];
      t = i;
    }
  }
  cout << t + 1 << endl;
}
