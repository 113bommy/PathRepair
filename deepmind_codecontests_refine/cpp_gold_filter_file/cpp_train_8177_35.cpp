#include <bits/stdc++.h>
using namespace std;
const int MAXN = 5e5 + 51;
int n, m;
int x[MAXN], y[MAXN];
bitset<2051> mat[2051], invl[2051];
inline int read() {
  register int num = 0, neg = 1;
  register char ch = getchar();
  while (!isdigit(ch) && ch != '-') {
    ch = getchar();
  }
  if (ch == '-') {
    neg = -1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    num = (num << 3) + (num << 1) + (ch - '0');
    ch = getchar();
  }
  return num * neg;
}
inline void elim() {
  int pivot;
  for (register int i = 1; i <= n; i++) {
    pivot = n + 1;
    for (register int j = i; j <= n; j++) {
      if (mat[j][i]) {
        pivot = j;
        break;
      }
    }
    swap(mat[i], mat[pivot]), swap(invl[i], invl[pivot]);
    for (register int j = 1; j <= n; j++) {
      mat[j][i] && j != i ? mat[j] ^= mat[i], invl[j] ^= invl[i], 1 : 1;
    }
  }
}
int main() {
  n = read(), m = read();
  for (register int i = 1; i <= m; i++) {
    x[i] = read(), y[i] = read(), mat[x[i]][y[i]] = 1;
  }
  for (register int i = 1; i <= n; i++) {
    invl[i][i] = 1;
  }
  elim();
  for (register int i = 1; i <= m; i++) {
    puts(invl[y[i]][x[i]] ? "NO" : "YES");
  }
}
