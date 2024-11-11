#include <bits/stdc++.h>
using namespace std;
int n, m, ed;
char a[155][155];
struct {
  int x;
  int y;
} b[155];
int Search(int q) {
  for (int i = q; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (a[i][j] == 'W') return 0;
    }
  }
  return 1;
}
int main() {
  int d = 0, start = 1, num, i, rn, j;
  cin >> n >> m;
  for (i = 1; i <= n; i++) {
    scanf("%s", a[i] + 1);
  }
  for (i = 1; i <= n; i++) {
    int cnt = 0;
    for (j = 1; j <= m; j++) {
      if (!cnt && a[i][j] == 'W') {
        cnt = 1;
        b[i].x = j;
      }
      if (a[i][j] == 'W') b[i].y = j;
    }
  }
  for (i = 1; i <= n; i++) {
    if (Search(i)) {
      rn = i - 1;
      break;
    }
  }
  if (i == n + 1) rn = n;
  if (b[1].x == 0 && b[1].y == 0 && b[2].x == 0 && b[2].y == 0) {
    b[2].x = b[2].y = 1;
  }
  for (i = 1; i < rn; i++) {
    if (i % 2) {
      if (b[i + 1].x == 0 && b[i + 1].y == 0) {
        b[i + 1].x = b[i + 1].y = b[i].y;
      }
      num = max(b[i].y, b[i + 1].y);
      d = d + num - start + 1;
      start = num;
    } else {
      if (b[i + 1].x == 0 && b[i + 1].y == 0) {
        b[i + 1].x = b[i + 1].y = b[i].x;
      }
      num = min(b[i].x, b[i + 1].x);
      d = d + start - num + 1;
      start = num;
    }
  }
  if (i == rn) {
    if (rn % 2 == 0) {
      if (b[i].x) d = d + start - b[i].x;
    } else {
      if (b[i].y) d = d + b[i].y - start;
    }
  }
  cout << d << endl;
  return 0;
}
