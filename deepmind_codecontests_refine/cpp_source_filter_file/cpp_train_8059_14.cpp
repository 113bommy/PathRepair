#include <bits/stdc++.h>
using namespace std;
template <typename T>
void read(T &x) {
  x = 0;
  char c = getchar();
  int sgn = 1;
  while (c < '0' || c > '9') {
    if (c == '-') sgn = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
  x *= sgn;
}
template <typename T>
void out(T x) {
  if (x < 0) {
    putchar('-');
    x = -x;
  }
  if (x >= 10) out(x / 10);
  putchar(x % 10 + '0');
}
const int N = 1e5 + 5;
int a[N];
int sum[11][N];
char s[N];
int main() {
  int n, k, w;
  read(n);
  read(k);
  read(w);
  scanf("%s", s + 1);
  for (int i = 1; i <= n; i++) {
    a[i] = a[i - 1] + (s[i] - '0');
    sum[i % k][i] = (s[i] - '0');
  }
  for (int i = 0; i < k; i++)
    for (int j = 1; j <= n; j++) sum[i][j] += sum[i][i - 1];
  while (w--) {
    int l, r;
    read(l);
    read(r);
    int ans = a[r] - a[l - 1] + (r - l + 1) / k -
              2 * (sum[r % k][r] - sum[r % k][l - 1]);
    out(ans);
    puts("");
  }
  return 0;
}
