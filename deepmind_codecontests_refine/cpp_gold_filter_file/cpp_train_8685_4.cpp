#include <bits/stdc++.h>
using namespace std;
int n, m, a[110], b[110];
void read(int &x) {
  char ch = getchar();
  int mark = 1;
  for (; ch != '-' && (ch < '0' || ch > '9'); ch = getchar())
    ;
  if (ch == '-') mark = -1, ch = getchar();
  for (x = 0; ch >= '0' && ch <= '9'; ch = getchar()) x = x * 10 + ch - 48;
  x *= mark;
}
int main() {
  read(n);
  read(m);
  if (n == 1)
    a[1] = 1;
  else if (n == 2)
    a[1] = 3, a[2] = 4;
  else if (n & 1) {
    a[1] = 2;
    for (int i = 2; i < n; i++) a[i] = 1;
    a[n] = (n + 1) / 2;
  } else {
    for (int i = 1; i < n; i++) a[i] = 1;
    a[n] = (n - 2) / 2;
  }
  if (m == 1)
    b[1] = 1;
  else if (m == 2)
    b[1] = 3, b[2] = 4;
  else if (m & 1) {
    b[1] = 2;
    for (int i = 2; i < m; i++) b[i] = 1;
    b[m] = (m + 1) / 2;
  } else {
    for (int i = 1; i < m; i++) b[i] = 1;
    b[m] = (m - 2) / 2;
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) printf("%d ", a[i] * b[j]);
    printf("\n");
  }
  return 0;
}
