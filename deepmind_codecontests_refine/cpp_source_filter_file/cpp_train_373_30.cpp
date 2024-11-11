#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  long long x = 0, f = 1;
  char c = getchar();
  while (!isdigit(c)) {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (isdigit(c)) {
    x = (x << 3) + (x << 1) + (c ^ 48);
    c = getchar();
  }
  return x * f;
}
const long long N = 100010;
long long sum[N << 4][10], sz[N << 4];
long long ls[N << 4], rs[N << 4], tot = 1, rt = 1;
long long n;
inline void push_up(long long x) {
  sz[x] = sz[ls[x]] + sz[rs[x]];
  for (long long i = 0; i < 5; i++) {
    sum[x][i] = sum[ls[x]][i] + sum[rs[x]][((i - sz[ls[x]] + 5) % 5)];
  }
}
inline void modify(long long &x, long long l, long long r, long long num,
                   long long opt) {
  if (!x) x = ++tot;
  if (l == r) {
    sum[x][1] += opt * num;
    sz[x] += opt;
    return;
  }
  long long mid = (l + r) / 2;
  if (num <= mid)
    modify(ls[x], l, mid, num, opt);
  else
    modify(rs[x], mid + 1, r, num, opt);
  push_up(x);
}
signed main() {
  n = read();
  for (long long i = 1; i <= n; i++) {
    char s[10];
    scanf("%s", s);
    if (s[0] == 'a') {
      long long x = read();
      modify(rt, 1, 1e9 + 1, x, 1);
    } else if (s[0] == 'd') {
      long long x = read();
      modify(rt, 1, 1e9 + 1, x, -1);
    } else
      cout << sum[1][3] << endl;
  }
}
