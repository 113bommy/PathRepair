#include <bits/stdc++.h>
using namespace std;
long long a[200002], b[200002], c[200002];
int n;
long long temp;
int f(long long x) {
  if (c[x] != 0) {
    return c[x];
  }
  long long xx = x;
  if (b[x] == 1) {
    c[x] = -1;
    return -1;
  }
  b[x] = 1;
  long long y = a[x];
  x += a[x];
  if (x > n) {
    c[xx] = y;
    b[xx] = 0;
    return y;
  }
  y += a[x];
  x -= a[x];
  if (x <= 0) {
    c[xx] = y;
    b[xx] = 0;
    return y;
  } else if (x == 1) {
    c[xx] = -1;
    b[xx] = 0;
    return -1;
  }
  temp = f(x);
  if (temp != -1) {
    c[xx] = temp + y;
    b[xx] = 0;
    return temp + y;
  } else {
    c[xx] = -1;
    b[xx] = 0;
    return -1;
  }
}
int main() {
  long long x, y;
  int i, j;
  scanf("%d", &n);
  for (i = 2; i <= n; i++) {
    cin >> a[i];
    b[i] = 0;
    c[i] = 0;
  }
  b[1] = b[0] = 0;
  c[1] = c[0] = 0;
  for (i = 2; i <= n; i++) {
    f(i);
  }
  for (i = 1; i < n; i++) {
    x = 1;
    y = 0;
    j = 0;
    a[1] = i;
    y += a[x];
    x += a[x];
    if (x > n) {
      cout << y << endl;
      continue;
    }
    y += a[x];
    x -= a[x];
    if (x <= 0) {
      cout << y << endl;
      continue;
    } else if (x == 1) {
      cout << "-1\n";
      continue;
    }
    if (c[x] == -1) {
      cout << "-1\n";
    } else {
      cout << c[x] + y << endl;
    }
  }
}
