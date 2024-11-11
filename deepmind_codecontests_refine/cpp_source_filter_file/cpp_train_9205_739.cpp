#include <bits/stdc++.h>
inline int read() {
  register char c = getchar();
  register int d = 0;
  while (!isdigit(c)) c = getchar();
  while (isdigit(c)) d = (d << 3) + (d << 1) + (c ^ 48), c = getchar();
  return d;
}
inline void write(int x) {
  if (x > 9) write(x / 10);
  putchar(x % 10 + '0');
}
const int n = 2;
int tree[n << 2];
inline void update(const int &p, const int &k) {
  for (register int i = p; i <= n; tree[i] += k, i += i & (-i))
    ;
}
inline int query(const int &p) {
  register int ans = 0;
  for (register int i = p; i > 0; ans += tree[i], i &= i - 1)
    ;
  return ans;
}
int main(int argc, const char *argv[]) {
  for (register int i = 1; i <= n; ++i) {
    int x = read();
    update(i, x);
  }
  write(query(n));
  putchar('\n');
  return 0;
}
