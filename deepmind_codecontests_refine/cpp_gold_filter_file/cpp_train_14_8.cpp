#include <bits/stdc++.h>
using namespace std;
const int N = 500010;
int n, m, d[N];
inline int read() {
  int sym = 0, res = 0;
  char ch = 0;
  while (!isdigit(ch)) sym |= (ch == '-'), ch = getchar();
  while (isdigit(ch)) res = (res << 3) + (res << 1) + (ch ^ 48), ch = getchar();
  return sym ? -res : res;
}
void file() {
  freopen("read.in", "r", stdin);
  freopen("write.out", "w", stdout);
}
int main() {
  n = read();
  for (int i = 1; i <= n - 1; i++) {
    int x = read(), y = read();
    d[x]++, d[y]++;
  }
  for (int i = 1; i <= n; i++) {
    if (d[i] == 2) {
      printf("NO");
      return 0;
    }
  }
  printf("YES");
  return 0;
}
