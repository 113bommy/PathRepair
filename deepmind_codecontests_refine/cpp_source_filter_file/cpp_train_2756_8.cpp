#include <bits/stdc++.h>
using namespace std;
long long read() {
  long long x = 0;
  char c = getchar();
  bool ok = 0;
  while (c < 48 || c > 57) ok |= (c == '-'), c = getchar();
  while (c > 47 && c < 58) x *= 10, x += c - 48, c = getchar();
  if (ok) x = -x;
  return x;
}
void print(long long x) { printf("%I64d\n", x); }
int a[100002];
int main() {
  int n = read();
  if (n == 1) {
    print(0);
    return 0;
  }
  for (int i = 0; i < n; i++) {
    a[i] = read();
  }
  int r = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] == 0) r++;
  }
  if (r == n - 1) {
    if (a[0] != 0)
      print(0);
    else
      print(1);
    return 0;
  }
  if (r == n - 2) {
    if (a[0] == 0)
      print(2);
    else if (a[1] != 0)
      print(0);
    else
      print(1);
    return 0;
  }
  if (a[0] == 0) {
    int cnt = 0;
    for (int i = 1; i < n; i++) cnt += (a[i] != 0);
    if (cnt <= 1) {
      print(cnt);
      return 0;
    } else if (a[1] == 0) {
      print(2);
      return 0;
    } else {
      int b = a[2], c = a[1];
      for (int i = 2; i < n; i++) {
        if (a[i] * c != a[i - 1] * b) {
          print(2);
          return 0;
        }
      }
      print(1);
      return 0;
    }
  }
  int cnt = 0, mi = 2;
  int b = a[1], d = a[0], c = a[0];
  if (d != 0) {
    for (int i = 1; i < n; i++) {
      if (a[i] * d == c * b) {
        c *= b;
        c /= d;
      } else
        cnt++;
    }
    if (cnt < 2) {
      mi = min(mi, cnt);
    }
  }
  cnt = 0;
  b = a[2], d = a[0], c = a[0];
  if (d != 0) {
    if (a[2] * d != a[1] * b || a[1] * d != a[0] * b) cnt++;
    for (int i = 3; i < n; i++) {
      if (a[i] * d == c * b) {
        c *= b;
        c /= d;
      } else
        cnt++;
    }
    if (cnt < 2) {
      mi = min(mi, cnt);
    }
  }
  cnt = 0;
  b = a[2], d = a[1], c = a[0];
  if (a[1] * d != a[0] * b) cnt++;
  if (d != 0) {
    for (int i = 3; i < n; i++) {
      if (a[i] * d == c * b) {
        c *= b;
        c /= d;
      } else
        cnt++;
    }
    if (cnt < 2) {
      mi = min(mi, cnt);
    }
  }
  print(mi);
  return 0;
}
