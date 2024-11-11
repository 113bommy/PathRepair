#include <bits/stdc++.h>
using namespace std;
int n;
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
  if (n == 5) {
    printf("1 2 1\n2 3 1\n3 4 1\n4 5 1\n1 4\n2 5\n");
  } else {
    int m = n / 2;
    for (int i = 1; i <= m; i++) printf("%d %d 1\n", i, i + m);
    for (int i = m + 1; i < n; i++)
      printf("%d %d %d\n", i, i + 1, (i - m) * 2 - 1);
    printf("1 3\n");
    for (int i = 1; i < m; i++) printf("%d %d\n", i, i + 1);
  }
  return 0;
}
