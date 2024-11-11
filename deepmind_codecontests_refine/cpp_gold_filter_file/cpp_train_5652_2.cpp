#include <bits/stdc++.h>
using namespace std;
inline int read() {
  char c = 0;
  int x = 0;
  bool f = 0;
  while (!isdigit(c)) f = c == '-', c = getchar();
  while (isdigit(c)) x = x * 10 + c - 48, c = getchar();
  return f ? -x : x;
}
const int N = 1e5 + 100;
int n, a[N], cnt, sum, ans[N][3];
int main() {
  n = read();
  sum = cnt = 0;
  for (int i = 1; i <= n; i++) sum ^= (a[i] = read());
  if (n % 2 == 0 && sum != 0) {
    printf("NO");
    return 0;
  }
  for (int i = 1; i + 2 <= n; i += 2) {
    ans[++cnt][0] = i;
    ans[cnt][1] = i + 1;
    ans[cnt][2] = i + 2;
  }
  for (int i = (n & 1 ? n - 4 : n - 5); i >= 1; i -= 2) {
    ans[++cnt][2] = i;
    ans[cnt][1] = i + 1;
    ans[cnt][0] = i + 2;
  }
  printf("YES\n%d", cnt);
  for (int i = 1; i <= cnt; i++) {
    printf("\n%d", ans[i][0]);
    printf(" %d %d", ans[i][1], ans[i][2]);
  }
  return 0;
}
