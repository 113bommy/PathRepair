#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}
int circles[90000][6], cnt;
inline void Add(int a, int b, int c, int d) {
  ++cnt;
  circles[cnt][0] = d == 0 ? 3 : 4;
  circles[cnt][1] = a;
  circles[cnt][2] = b;
  circles[cnt][3] = c;
  circles[cnt][4] = d;
}
inline void solve(int x) {
  if (x <= 2) {
    puts("-1");
    exit(0);
  }
  if (x == 4) {
    Add(1, 2, 3, 0);
    Add(2, 3, 4, 0);
    Add(3, 4, 1, 0);
    Add(4, 1, 2, 0);
    return;
  }
  if (x == 3) {
    Add(1, 2, 3, 0);
    Add(1, 2, 3, 0);
    return;
  }
  solve(x - 2);
  for (int i = 1; i <= x - 3; i++) Add(x, i, x - 1, i + 1);
  Add(x, x - 2, x - 1, 0);
  Add(x, 1, x - 1, 0);
}
int main() {
  solve(read());
  printf("%d\n", cnt);
  for (int k = 1; k <= cnt; k++, puts(""))
    for (int i = 0; i <= circles[k][0]; i++) printf("%d ", circles[k][i]);
  return 0;
}
