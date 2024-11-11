#include <bits/stdc++.h>
using namespace std;
int i, j, k, l, p[110], q[110], s, t, a[100][100], b[100][100];
char c;
int main() {
  for (i = 0; i < 8; i++)
    for (j = 0; j < 8; j++) {
      cin >> c;
      if (c == 'S') b[i][j] = 1;
    }
  a[7][0] = 1;
  while (1) {
    k = 1;
    for (i = 0; i < 8 && k; i++)
      for (j = 0; j < 8 && k; j++)
        if (b[i][j]) k = 0;
    if (k) break;
    s = 0;
    for (i = 0; i < 8; i++)
      for (j = 0; j < 8; j++) {
        if (a[i][j]) {
          p[s] = i;
          q[s] = j;
          s++;
        }
      }
    for (t = 0; t < s; t++) {
      i = p[t];
      j = q[t];
      if (i > 0 && !b[i - 1][j]) a[i - 1][j] = 1;
      if (i < 7 && !b[i + 1][j]) a[i + 1][j] = 1;
      if (j > 0 && !b[i][j - 1]) a[i][j - 1] = 1;
      if (j < 7 && !b[i][j + 1]) a[i][j + 1] = 1;
      if (i > 0 && j > 0 && !b[i - 1][j - 1]) a[i - 1][j - 1] = 1;
      if (i < 7 && j < 7 && !b[i + 1][j + 1]) a[i + 1][j + 1] = 1;
      if (i > 0 && j < 7 && !b[i - 1][j + 1]) a[i - 1][j + 1] = 1;
      if (i < 7 && j > 0 && !b[i + 1][j - 1]) a[i + 1][j - 1] = 1;
    }
    s = 0;
    for (i = 7; i >= 0; i--)
      for (j = 0; j < 8; j++)
        if (b[i][j]) {
          p[s] = i;
          q[s] = j;
          s++;
        }
    for (t = 0; t < s; t++) {
      i = p[t];
      j = q[t];
      b[i][j] = 0;
      if (i < 7) b[i + 1][j] = 1;
    }
    l = 1;
    for (i = 0; i < 8; i++)
      for (j = 0; j < 8; j++)
        if (a[i][j]) {
          if (b[i][j])
            a[i][j] = 0;
          else {
            l = 0;
          }
        }
    if (l) {
      k = 0;
      break;
    }
  }
  if (k)
    cout << "WIN";
  else
    cout << "LOSE";
  return 0;
}
