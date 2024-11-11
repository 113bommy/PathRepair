#include <bits/stdc++.h>
using namespace std;
int d[10][4], test[4], n;
int a[10], b[10];
char c;
bool check() {
  int x = 0;
  int y = 0;
  bool dig[10];
  memset(&dig, 0, sizeof(dig));
  for (int i = 0, _n = (4); i < _n; i++) dig[test[i]] = 1;
  for (int i = 0, _n = (n); i < _n; i++) {
    x = 0;
    y = 0;
    for (int j = 0, _n = (4); j < _n; j++) {
      if (test[j] == d[i][j])
        x++;
      else
        y += dig[d[i][j]];
    }
    if (x != a[i] || y != b[i]) return 0;
  }
  return 1;
}
int main() {
  scanf("%d\n", &n);
  for (int i = 0, _n = (n); i < _n; i++) {
    for (int j = 0, _n = (4); j < _n; j++) {
      scanf("%c", &c);
      d[i][j] = c - '0';
    }
    scanf("%d%d\n", &a[i], &b[i]);
  }
  int num = 0, count = 0;
  for (int d1 = 0, _n = (10); d1 < _n; d1++) {
    for (int d2 = 0, _n = (10); d2 < _n; d2++) {
      for (int d3 = 0, _n = (10); d3 < _n; d3++) {
        for (int d4 = 0, _n = (10); d4 < _n; d4++) {
          if (d1 == d2 || d2 == d3 || d3 == d4 || d4 == d1 || d4 == d2 ||
              d1 == d3)
            continue;
          test[0] = d1;
          test[1] = d2;
          test[2] = d3;
          test[3] = d4;
          if (check()) {
            count++;
            num = d4 + 10 * d3 + 100 * d2 + 1000 * d1;
          }
        }
      }
    }
  }
  if (count == 0)
    printf("Incorrect data\n");
  else if (count == 1)
    printf("%d\n", num);
  else
    printf("Need more data\n");
  return 0;
}
