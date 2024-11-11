#include <bits/stdc++.h>
using namespace std;
int read() {
  int x = 0, f = 1;
  char ch = getchar();
  while (ch - '0' < 0 || ch - '0' > 9) {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch - '0' >= 0 && ch - '0' <= 9) {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}
struct P {
  int x, y;
} a[500010];
int n, m;
bitset<2010 * 2> A[2010];
void get_det() {
  for (int i = 1; i <= n; i++) {
    int pos;
    for (pos = i; pos <= n && (!A[pos][i]); pos++)
      ;
    if (pos > n) continue;
    if (pos != i) swap(A[pos], A[i]);
    for (int j = 1; j <= n; j++)
      if (A[j][i] && i != j) A[j] ^= A[i];
  }
}
int main() {
  n = read();
  m = read();
  for (int i = 1; i <= m; i++) a[i].x = read(), a[i].y = read();
  for (int i = 1; i <= m; i++) A[a[i].x][a[i].y] = 1;
  for (int i = 1; i <= n; i++) A[i][i + n] = 1;
  get_det();
  for (int i = 1; i <= m; i++) {
    if (A[a[i].x][a[i].y + n])
      puts("NO");
    else
      puts("YES");
  }
  return 0;
}
