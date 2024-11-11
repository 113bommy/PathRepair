#include <bits/stdc++.h>
#pragma GCC optimize(3, "Ofast", "inline")
#pragma GCC target("avx,avx2")
using namespace std;
template <class t>
inline t read(t &x) {
  char c = getchar();
  bool f = 0;
  x = 0;
  while (!isdigit(c)) f |= c == '-', c = getchar();
  while (isdigit(c)) x = (x << 1) + (x << 3) + (c ^ 48), c = getchar();
  if (f) x = -x;
  return x;
}
template <class t, class... A>
inline void read(t &x, A &...a) {
  read(x);
  read(a...);
}
template <class t>
inline void write(t x) {
  if (x < 0)
    putchar('-'), write(-x);
  else {
    if (x > 9) write(x / 10);
    putchar('0' + x % 10);
  }
}
int n, ans, ma[2000005];
vector<int> a;
signed main() {
  read(n);
  for (int i = 1, x; i <= n; i++) a.push_back(read(x)), ma[x] = x;
  sort(a.begin(), a.end());
  a.erase(unique(a.begin(), a.end()), a.end());
  for (int i = 1; i <= 2e6; i++) ma[i] = max(ma[i], ma[i - 1]);
  for (int i = 0; i < a.size(); i++)
    for (int j = 1; j * a[i] <= 1000000; j++)
      ans = max(ans, ma[(j + 1) * a[i] - 1] >= j * a[i]
                         ? ma[(j + 1) * a[i] - 1] - j * a[i]
                         : 0);
  write(ans);
}
