#include <bits/stdc++.h>
using namespace std;
inline int readint() {
  int a = 0, f = 1;
  char c = getchar();
  for (; c < '0' || c > '9'; c = getchar())
    if (c == '-') f = -f;
  for (; '0' <= c && c <= '9'; c = getchar())
    a = (a << 3) + (a << 1) + (c ^ 48);
  return a * f;
}
inline void writeint(long long x) {
  if (x < 0) putchar('-'), x = -x;
  if (x > 9) writeint(x / 10);
  putchar((x % 10) ^ 48);
}
template <typename T>
void getMax(T &a, const T &b) {
  if (a < b) a = b;
}
template <typename T>
void getMin(T &a, const T &b) {
  if (b < a) a = b;
}
const int MaxN = 200020 << 2, infty = (1 << 30) - 1;
int n, r[MaxN], a[MaxN], d[MaxN], M;
set<int> ans;
void manacher() {
  for (int i = 0; i <= (n << 1); ++i) {
    d[i << 1] = a[i + 1] - a[i];
    d[i << 1 | 1] = -5201314;
  }
  d[0] = -infty, d[n << 2] = infty;
  for (int i = 1, id = 0; i < (n << 2); ++i) {
    if (i < id + r[id]) r[i] = min(id + r[id] - i, r[id * 2 - i]);
    while (d[i - r[i] - 1] == d[i + r[i] + 1]) ++r[i];
    if (i + r[i] > id + r[id]) id = i;
    if (r[i] >= n - 1) {
      int x = a[(i + 1) >> 1], y = a[(i + 2) >> 1];
      ans.insert(((0ll + (x) + (y)) % M));
    }
  }
}
int main() {
  n = readint(), M = readint();
  for (int i = 1; i <= n; ++i) a[i] = readint(), a[i + n] = a[i] + M;
  manacher(), printf("%d\n", int(ans.size()));
  for (auto i : ans) printf("%d ", i);
  puts("");
  return 0;
}
