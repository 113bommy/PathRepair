#include <bits/stdc++.h>
using namespace std;
inline void writeInt(int x) {
  if (x == -1) {
    putchar('-');
    putchar('1');
    putchar('\n');
  } else {
    int i = 10;
    char buf[11];
    buf[10] = ' ';
    do {
      buf[--i] = x % 10 + '0';
      x /= 10;
    } while (x);
    do {
      putchar(buf[i]);
    } while (buf[i++] != ' ');
  }
}
inline void fastInput(int &x) {
  register int c = getchar();
  x = 0;
  int neg = 0;
  for (; ((c < 48 || c > 57) && c != '-'); c = getchar())
    ;
  if (c == '-') {
    neg = 1;
    c = getchar();
  }
  for (; c > 47 && c < 58; c = getchar()) {
    x = (x << 1) + (x << 3) + c - 48;
  }
  if (neg) x = -x;
}
struct stu {
  int x, y;
} a[1002];
int main() {
  int i, n;
  cin >> n;
  for (i = 0; i < n; i++) cin >> a[i].x >> a[i].y;
  int idx[2], idy[2];
  idx[0] = a[0].x;
  for (i = 1; i < n; i++) {
    if (a[i].x < idx[0]) idx[0] = a[i].x;
  }
  idx[1] = a[0].x;
  for (i = 1; i < n; i++) {
    if (a[i].x > idx[1]) idx[1] = a[i].x;
  }
  idy[0] = a[0].y;
  for (i = 1; i < n; i++) {
    if (a[i].y < idy[0]) idy[0] = a[i].y;
  }
  idy[1] = a[0].y;
  for (i = 1; i < n; i++) {
    if (a[i].y > idy[1]) idy[1] = a[i].y;
  }
  long long ans;
  long long rr = abs(idx[1] - idx[0]), yy = abs(idy[1] - idy[0]);
  if (rr >= yy) {
    ans = rr * rr;
  } else {
    ans = yy * yy;
  }
  cout << ans << endl;
  return 0;
}
