#include <bits/stdc++.h>
using namespace std;
int n;
int sum, flag, cnt;
int a[200007];
inline int read() {
  int x = 0;
  int flag = 1;
  char ch;
  ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') flag = -1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    x = (x << 1) + (x << 3) + ch - 48;
    ch = getchar();
  }
  return x * flag;
}
int main() {
  n = read();
  if (!(n & 1)) {
    printf("NO\n");
    return 0;
  }
  printf("YES\n");
  int l = 0;
  int r = 0;
  for (register int i = 1; i < n; i += 2) {
    a[++l] = ++cnt;
    for (register int j = 1; j <= 2; j++) {
      a[++r + n] = ++cnt;
    }
    a[++l] = ++cnt;
  }
  a[++l] = ++cnt;
  a[++r + n] = ++cnt;
  for (register int i = 1; i <= n << 1; i++) {
    cout << a[i] << " ";
  }
  return 0;
}
