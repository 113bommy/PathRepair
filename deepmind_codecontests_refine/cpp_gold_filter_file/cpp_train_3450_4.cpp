#include <bits/stdc++.h>
using namespace std;
namespace fast_IO {
template <typename T>
inline void read(T &x) {
  x = 0;
  register char c = getchar(), pre = 0;
  for (; c < '0' || c > '9'; pre = c, c = getchar())
    ;
  for (; c >= '0' && c <= '9'; x = x * 10 + (c ^ 48), c = getchar())
    ;
  if (pre == '-') x = -x;
}
template <typename T>
void print(T x) {
  if (x < 0) x = -x, putchar('-');
  if (x > 9) print(x / 10);
  putchar(x % 10 + '0');
}
template <typename T>
inline T Min(T x, T y) {
  return x < y ? x : y;
}
template <typename T>
inline T Max(T x, T y) {
  return x > y ? x : y;
}
template <typename T>
inline T Abs(T x) {
  return x < 0 ? -x : x;
}
}  // namespace fast_IO
using namespace fast_IO;
const int N = 150010;
int n, a[N], b[N], f1[N], f2[N], u;
int nxt[N], lst[N];
int find1(int x) { return x == f1[x] ? x : f1[x] = find1(f1[x]); }
int find2(int x) { return x == f2[x] ? x : f2[x] = find2(f2[x]); }
int main() {
  read(n), f1[1] = f2[1] = 1;
  for (int i = (2), ied = (n); i <= ied; i++)
    read(a[i]), read(b[i]), f1[i] = f2[i] = i;
  for (int i = (2), ied = (n); i <= ied; i++) {
    int lu = find1(a[i]), ru = find2(a[i]), lv = find1(b[i]), rv = find2(b[i]);
    nxt[ru] = lv, lst[lv] = ru, f1[lv] = lu, f2[ru] = rv;
  }
  for (int i = (1), ied = (n); i <= ied; i++)
    if (!lst[i]) u = i;
  for (; u;) printf("%d ", u), u = nxt[u];
  return 0;
}
