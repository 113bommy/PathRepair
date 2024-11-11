#include <bits/stdc++.h>
const int N = 155;
bool b[N][N];
int c[N];
void add(int i, int j) { b[i][j] = b[j][i] = true; }
int main() {
  int k, n = 3, i;
  scanf("%d", &k);
  if (k == 1) {
    puts("2\nNY\nYN");
    return 0;
  }
  for (i = 30; i >= 0; --i)
    if (k & (1 << i)) {
      add(1, 3), add(1, 4);
      c[1] = 1;
      if (k < 4) {
        add(3, 2), add(4, 2);
        c[2] = 2;
        n = 4;
        break;
      }
      add(3, 5), add(4, 5);
      int now = 5;
      c[1] = 1;
      for (int j = 2; j < i; ++j) {
        add(now, now + 1), add(now, now + 2), add(now + 1, now + 3),
            add(now + 2, now + 3);
        c[j] = now;
        now += 3;
      }
      c[i] = now;
      c[i + 1] = 2;
      add(now, now + 1), add(now, now + 2), add(now + 1, 2), add(now + 2, 2);
      n = now + 2;
      break;
    }
  const int g = n, kk = i;
  int lst = i, lto = c[1], id = 1;
  for (--i; i >= 0; --i)
    if (k & (1 << i)) {
      while (n - g < 2 * (kk - i) - 1) add(++n, id), id = n;
      add(n, c[kk - i + 1]);
    }
  printf("%d\n", n);
  for (int i = 1; i <= n; puts(""), ++i)
    for (int j = 1; j <= n; ++j) putchar(b[i][j] ? 'Y' : 'N');
}
