#include <bits/stdc++.h>
using namespace std;
bool b[1000100];
int n, m, q[1000100], from[50], to[50];
int len(int x) {
  int l = 1;
  while (x / 10 != 0) {
    l++;
    x /= 10;
  }
  return l;
}
int fd(int x) {
  while (x / 10 != 0) {
    x /= 10;
  }
  return x;
}
int pow(int x) {
  int p = 1;
  while (x / 10 != 0) {
    p *= 10;
    x /= 10;
  }
  return p;
}
int main() {
  scanf("%d%d\n", &n, &m);
  for (int i = 1; i <= m; i++) {
    char ch1, ch2, ch3;
    int i1, i2, i3;
    scanf("%c%c %c\n", &ch1, &ch2, &ch3);
    i1 = int(ch1 - 'a') + 1;
    i2 = int(ch2 - 'a') + 1;
    i3 = int(ch3 - 'a') + 1;
    from[i] = i3;
    to[i] = i1 * 10 + i2;
  }
  int nq = 1;
  q[1] = 1;
  b[1] = 1;
  int i = 0;
  int ans = 0;
  while (i < nq) {
    i++;
    int f = fd(q[i]);
    int l = len(q[i]);
    int p = pow(q[i]);
    if (l < n) {
      for (int j = 1; j <= m; j++) {
        if (f == from[j]) {
          int nt = q[i] / (p * 10) + to[j] * p;
          if (!b[nt]) {
            b[nt] = 1;
            nq++;
            q[nq] = nt;
          }
        }
      }
    } else {
      ans++;
    }
  }
  printf("%d\n", ans);
  return 0;
}
