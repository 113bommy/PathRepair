#include <bits/stdc++.h>
using namespace std;
template <class T>
inline void putnum(T x) {
  if (x < 0) putchar('-'), x = -x;
  register short a[20] = {}, sz = 0;
  while (x) a[sz++] = x % 10, x /= 10;
  if (sz == 0) putchar('0');
  for (int i = sz - 1; i >= 0; i--) putchar('0' + a[i]);
  putchar(' ');
}
int n, w, dat[1005], res[1005], sum = 0, pos = -1;
int main() {
  cin >> n >> w;
  for (int i = 1; i <= n; i++) {
    cin >> dat[i], sum += dat[i];
    if (dat[i] == 1) pos = i;
  }
  if (w < 1 || w > sum || (n == 1 && w != sum) || (w == 1 && pos == -1))
    return puts("No"), 0;
  puts("Yes");
  if (n == 1)
    for (int i = 1; i <= 2 * dat[1]; i++) putnum(1);
  else if (w == 1) {
    dat[pos]--;
    putnum(pos);
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= 2 * dat[i]; j++) putnum(i);
    putnum(pos);
  } else {
    w = w - 2;
    dat[1]--;
    dat[2]--;
    for (int i = 2; i <= n; i++)
      while (w && dat[i]) res[i]++, w--, dat[i]--;
    putnum(1);
    for (int i = 2; i <= n; i++)
      for (int j = 1; j <= 2 * dat[i]; j++) putnum(i);
    putnum(1);
    putnum(2);
    for (int i = 1; i <= 2 * dat[1]; i++) putnum(1);
    putnum(2);
    for (int i = 2; i <= n; i++)
      for (int j = 1; j <= 2 * res[i]; j++) putnum(i);
  }
  return 0;
}
