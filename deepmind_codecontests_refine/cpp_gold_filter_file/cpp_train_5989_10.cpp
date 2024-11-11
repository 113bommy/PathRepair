#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, n, i, j, tot, d;
  a = 0;
  string s;
  cin >> n;
  string q[n];
  int b[n];
  int c[n];
  for (d = 0; d < n; d++) {
    b[d] = 0;
  }
  for (d = 0; d < n; d++) {
    c[d] = 0;
  }
  for (i = 0; i < n; i++) {
    cin >> s;
    q[i] = s;
  }
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      if (q[i][j] == 'C') {
        b[i]++;
      }
    }
  }
  for (j = 0; j < n; j++) {
    for (i = 0; i < n; i++) {
      if (q[i][j] == 'C') {
        c[j]++;
      }
    }
  }
  for (i = 0; i < n; i++) {
    a += (b[i] * (b[i] - 1) / 2);
  }
  for (j = 0; j < n; j++) {
    a += (c[j] * (c[j] - 1) / 2);
  }
  cout << a;
}
