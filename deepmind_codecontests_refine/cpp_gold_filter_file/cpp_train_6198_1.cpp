#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline void read(T &x) {
  short f = 1;
  x = 0;
  char c = getchar();
  while (!isdigit(c)) {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (isdigit(c)) x = (x << 3) + (x << 1) + (c ^ 48), c = getchar();
  x *= f;
}
template <typename T>
inline void write(T x) {
  if (x < 0) putchar('-'), x = -x;
  if (x > 9) write(x / 10);
  putchar(x % 10 + '0');
}
template <typename T>
inline void writeln(T x) {
  write(x), putchar('\n');
}
int main() {
  int n, a[20], b[20], ans = 0;
  read(n);
  for (int i = 1; i <= n; i++) read(a[i]);
  for (int i = 1; i <= n; i++) read(b[i]);
  for (int j = 0; j <= 720720; j++)
    for (int i = 1; i <= n; i++)
      if (j % a[i] == b[i]) {
        ans++;
        break;
      }
  cout << ans / 720720.0 << endl;
  return 0;
}
