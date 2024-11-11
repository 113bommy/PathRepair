#include <bits/stdc++.h>
using namespace std;
const int ma = 10000007;
long long t, n, i, j, k, m, s1 = 0, a1, b1, c1, d1;
char a[101][101];
string s;
int main() {
  for (i = 1; i <= 25; i++) {
    for (j = 1; j <= 25; j++) {
      a[i][j] = 'A';
    }
  }
  for (i = 1; i <= 25; i++) {
    for (j = 26; j <= 50; j++) {
      a[i][j] = 'B';
    }
  }
  for (i = 26; i <= 50; i++) {
    for (j = 1; j <= 25; j++) {
      a[i][j] = 'C';
    }
  }
  for (i = 26; i <= 50; i++) {
    for (j = 26; j <= 50; j++) {
      a[i][j] = 'D';
    }
  }
  cin >> a1 >> b1 >> c1 >> d1;
  a1--;
  if (a1)
    for (i = 26; i <= 50; i++) {
      if (i % 2 == 0)
        for (j = 27; j <= 50; j += 2) {
          a[i][j] = 'A';
          a1--;
          if (a1 == 0) break;
        }
      if (a1 == 0) break;
    }
  b1--;
  if (b1)
    for (i = 1; i <= 25; i++) {
      if (i % 2 == 0)
        for (j = 2; j <= 25; j += 2) {
          a[i][j] = 'B';
          b1--;
          if (b1 == 0) break;
        }
      if (b1 == 0) break;
    }
  c1--;
  if (c1)
    for (i = 1; i <= 25; i++) {
      if (i % 2 == 0)
        for (j = 27; j <= 50; j += 2) {
          a[i][j] = 'C';
          c1--;
          if (c1 == 0) break;
        }
      if (c1 == 0) break;
    }
  d1--;
  if (d1)
    for (i = 1; i <= 25; i++) {
      if (i % 2 == 0)
        for (j = 2; j <= 25; j += 2) {
          a[i][j] = 'D';
          d1--;
          if (d1 == 0) break;
        }
      if (d1 == 0) break;
    }
  cout << 50 << " " << 50 << "\n";
  for (i = 1; i <= 50; i++) {
    for (j = 1; j <= 50; j++) {
      cout << a[i][j];
    }
    cout << "\n";
  }
}
