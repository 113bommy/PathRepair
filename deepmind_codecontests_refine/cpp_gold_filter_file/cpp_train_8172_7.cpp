#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, c = 0, s = 0, a[1000][1000] = {0}, i, j, k, x, y, c1 = 0, c2 = 0;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d%d", &x, &y);
    x--;
    y--;
    a[x][y] = 1;
  }
  n = 1000;
  for (j = 0; j < n; j++) {
    i = 0;
    k = j;
    c = 0;
    while (k >= 0) {
      if (a[i][k]) c++;
      i++;
      k--;
    }
    s += (c * (c - 1)) / 2;
  }
  for (i = 1; i < n; i++) {
    k = i;
    j = n - 1;
    c = 0;
    while (k < n) {
      if (a[k][j]) c++;
      k++;
      j--;
    }
    s += (c * (c - 1)) / 2;
  }
  for (j = n - 1; j >= 0; j--) {
    k = j;
    i = 0;
    c = 0;
    while (k < n) {
      if (a[i][k]) c++;
      i++;
      k++;
    }
    s += (c * (c - 1)) / 2;
  }
  for (i = 1; i < n; i++) {
    k = i;
    j = 0;
    c = 0;
    while (k < n) {
      if (a[k][j]) c++;
      j++;
      k++;
    }
    s += (c * (c - 1)) / 2;
  }
  cout << s;
}
