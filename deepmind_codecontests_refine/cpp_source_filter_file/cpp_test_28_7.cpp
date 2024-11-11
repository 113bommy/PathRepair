#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline void read(T &x) {
  x = 0;
  char c = getchar(), f = 0;
  for (; c < 48 || c > 57; c = getchar())
    if (!(c ^ 45)) f = 1;
  for (; c >= 48 && c <= 57; c = getchar()) x = (x << 1) + (x << 3) + (c ^ 48);
  f ? x = -x : x;
}
template <typename T, typename... L>
inline void read(T &x, L &...l) {
  read(x), read(l...);
}
int a, b, c;
inline void solve() {
  read(a, b, c);
  printf("%d\n", (a + b * 2 + c * 3) % 2);
}
int main() {
  int Ca;
  for (read(Ca); Ca--;) solve();
  return 0;
}
