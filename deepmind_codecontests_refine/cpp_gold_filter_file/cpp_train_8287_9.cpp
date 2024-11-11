#include <bits/stdc++.h>
using namespace std;
inline int read() {
  char c;
  int s = 0, t = 1;
  while (!isdigit(c = getchar()))
    if (c == '-') t = -1;
  do {
    s = s * 10 + c - '0';
  } while (isdigit(c = getchar()));
  return s * t;
}
inline long long readl() {
  char c;
  long long s = 0;
  int t = 1;
  while (!isdigit(c = getchar()))
    if (c == '-') t = -1;
  do {
    s = s * 10 + c - '0';
  } while (isdigit(c = getchar()));
  return s * t;
}
int a[10];
int main() {
  int n;
  n = read();
  n--;
  int c = 1 << 30;
  for (int i = 1; i <= 3; i++) {
    a[i] = read();
    c = min(c, a[i]);
  }
  if (c == a[3] && n) {
    printf("%d\n", c * (n - 1) + min(a[1], a[2]));
  } else {
    printf("%d\n", c * n);
  }
}
