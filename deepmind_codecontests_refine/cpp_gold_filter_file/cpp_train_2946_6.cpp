#include <bits/stdc++.h>
using namespace std;
template <class T>
void read(T &x) {
  int f = 0;
  x = 0;
  char ch = getchar();
  for (; !isdigit(ch); ch = getchar()) f |= (ch == '-');
  for (; isdigit(ch); ch = getchar()) x = x * 10 + ch - '0';
  if (f) x = -x;
}
const int N = 1000005;
int f0[N << 2], f1[N << 2], c0[N << 2], c1[N << 2], t[N << 2];
int n, m, x, y;
char s[N];
void up(int o) {
  f0[o] = max(f0[(o << 1)] + c1[(o << 1 | 1)], c0[(o << 1)] + f0[(o << 1 | 1)]);
  f1[o] = max(f1[(o << 1)] + c0[(o << 1 | 1)], c1[(o << 1)] + f1[(o << 1 | 1)]);
  c0[o] = c0[(o << 1)] + c0[(o << 1 | 1)];
  c1[o] = c1[(o << 1)] + c1[(o << 1 | 1)];
}
void build(int o, int l, int r) {
  if (l == r) {
    if (s[l] == '4')
      c0[o] = 1;
    else
      c1[o] = 1;
    f0[o] = f1[o] = 1;
    return;
  }
  build((o << 1), l, ((l + r) >> 1)),
      build((o << 1 | 1), ((l + r) >> 1) + 1, r);
  up(o);
}
void app(int o) {
  swap(f1[o], f0[o]);
  swap(c1[o], c0[o]);
  t[o] ^= 1;
}
void down(int o) {
  if (!t[o]) return;
  app((o << 1)), app((o << 1 | 1)), t[o] = 0;
}
void upd(int o, int l, int r, int x, int y) {
  if (l == x && y == r) {
    app(o);
    return;
  }
  down(o);
  if (x <= ((l + r) >> 1))
    upd((o << 1), l, ((l + r) >> 1), x, min(y, ((l + r) >> 1)));
  if (((l + r) >> 1) < y)
    upd((o << 1 | 1), ((l + r) >> 1) + 1, r, max(((l + r) >> 1) + 1, x), y);
  up(o);
}
int main() {
  read(n), read(m);
  scanf("%s", s + 1);
  build(1, 1, n);
  while (m--) {
    static char op[5];
    scanf("%s", op);
    if (op[0] == 's') {
      read(x), read(y);
      upd(1, 1, n, x, y);
    } else {
      printf("%d\n", f0[1]);
    }
  }
  return 0;
}
