#include <bits/stdc++.h>
using namespace std;
inline void readInt(int &x) {
  x = 0;
  int f = 1;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
  x *= f;
}
inline void readLong(long long &x) {
  x = 0;
  int f = 1;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
  x *= f;
}
int n, mx, cnt[300050], tot = 0;
long long k, sum;
inline void P(int pos) {
  if (pos == mx) {
    for (int i = 1; i <= cnt[pos]; i++) printf("()");
    return;
  }
  putchar('(');
  P(pos + 1);
  putchar(')');
  for (int i = 1; i < cnt[pos]; i++) printf("()");
}
int main() {
  readInt(n);
  readLong(k);
  for (mx = 0; mx < n && sum + mx <= k; mx++) {
    cnt[mx] = 1;
    tot++;
    sum += mx;
  }
  if (mx == n && sum < k) {
    puts("Impossible");
    return 0;
  }
  for (int i = mx; i >= 1; i--) {
    while (sum + i <= k) {
      cnt[i]++;
      sum += i;
      tot++;
    }
  }
  if (tot > n) {
    puts("Impossible");
    return 0;
  }
  cnt[0] += n - tot;
  P(0);
  return 0;
}
