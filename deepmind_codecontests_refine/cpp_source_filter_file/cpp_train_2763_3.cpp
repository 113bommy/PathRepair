#include <bits/stdc++.h>
using namespace std;
struct pos {
  int x, y;
} a[15], b[15];
int n;
char s[15];
int main() {
  b[0].x = 3;
  b[0].y = 1;
  for (int i = 1; i < 10; i++) {
    b[i].x = (i - 1) / 3;
    b[i].y = (i - 1) % 3;
  }
  bool g = true;
  cin >> n >> s;
  for (int i = 0; i < n; i++) {
    a[i] = b[s[i] - '0'];
    if (s[i] == '0') {
      g = true;
    }
  }
  int mini = 10, maxi = 0, minj = 10, maxj = 0;
  bool f = true;
  for (int i = 0; i < n; i++) {
    mini = min(mini, a[i].x);
    maxi = max(maxi, a[i].x);
    minj = min(minj, a[i].y);
    maxj = max(maxj, a[i].y);
    if (a[i].x == 2 && a[i].y != 1) {
      f = false;
    }
  }
  if (!f) {
    if (mini > 0) {
      puts("No");
    } else if (g && (minj > 0 || maxj < 2)) {
      puts("No");
    } else {
      puts("Yes");
    }
  } else {
    if (mini > 0 || maxi < 3) {
      puts("No");
    } else if (g && (minj > 0 || maxj < 2)) {
      puts("No");
    } else {
      puts("Yes");
    }
  }
  return 0;
}
