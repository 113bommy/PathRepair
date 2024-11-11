#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 9;
namespace FastIO {
inline int read() {
  int x = 0, F = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') F = (ch == '-') ? -1 : 1, ch = getchar();
  while (ch >= '0' && ch <= '9')
    x = (x << 1) + (x << 3) + (ch & 15), ch = getchar();
  return x * F;
}
inline void write(int x) {
  if (x < 0) putchar('-'), x = ~x + 1;
  if (x > 9) write(x / 10);
  putchar((x % 10) | 48);
}
inline void write(int x, char ch) { write(x), putchar(ch); }
}  // namespace FastIO
using namespace FastIO;
int n, ans;
set<int> st[2];
struct Segment {
  int l, r, col;
  bool operator<(const Segment &tmp) const { return r < tmp.r; }
} s[N];
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++)
    s[i].l = read(), s[i].r = read(), s[i].col = read() - 1;
  sort(s + 1, s + n + 1);
  ans = n;
  for (int i = 1; i <= n; i++) {
    if (st[s[i].col ^ 1].lower_bound(s[i].l) != st[s[i].col ^ 1].end())
      ans--, st[s[i].col ^ 1].erase(st[s[i].col ^ 1].lower_bound(s[i].l));
    else
      st[s[i].col].insert(s[i].r);
  }
  cout << ans << endl;
  return 0;
}
