#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int s = 1, a = 0;
  char c = getchar();
  if (!isdigit(c)) {
    if (c == '-') s = -s;
    c = getchar();
  }
  if (isdigit(c)) {
    a = a * 10 + c - '0';
    c = getchar();
  }
  return s * a;
}
const int N = 2e3 + 5;
int n, a[N];
bool cmp(int x, int y) { return a[x] > a[y]; }
int ans[N][N], rk[N], rev[N];
int main() {
  n = read();
  for (int i = 1; i <= n; i++) {
    a[i] = read();
    rk[i] = i;
  }
  sort(rk + 1, rk + n + 1, cmp);
  for (int i = 1; i <= n; i++) rev[rk[i]] = i;
  printf("%d\n", n + 1);
  for (int i = 1; i <= n; i++) {
    int cnt = 0, idx = i;
    while (cnt < a[rk[i]]) {
      ans[idx][rk[i]] = 1;
      cnt++;
      if (idx == n + 1)
        idx = 1;
      else
        idx++;
    }
  }
  for (int i = 1; i <= n + 1; i++) {
    for (int j = 1; j <= n; j++) {
      printf("%d", ans[i][j]);
    }
    printf("\n");
  }
  return 0;
}
