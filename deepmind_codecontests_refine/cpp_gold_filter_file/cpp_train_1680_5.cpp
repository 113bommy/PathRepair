#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline bool chkmin(T &a, const T &b) {
  return a > b ? a = b, 1 : 0;
}
template <typename T>
inline bool chkmax(T &a, const T &b) {
  return a < b ? a = b, 1 : 0;
}
template <typename T>
inline T read() {
  register T sum(0), fg(1);
  register char ch(getchar());
  for (; !isdigit(ch); ch = getchar())
    if (ch == '-') fg = -1;
  for (; isdigit(ch); ch = getchar()) sum = sum * 10 - '0' + ch;
  return sum * fg;
}
const int MAXN = 500;
int n;
struct offer {
  int a, b, k;
  inline bool operator<(const offer &rhs) const { return this->b > rhs.b; }
} c[MAXN + 5];
inline void input() {
  n = read<int>();
  for (int i = 0; i < n; ++i)
    c[i].a = read<int>(), c[i].b = read<int>(), c[i].k = read<int>();
}
inline void solve() {
  static long long f[MAXN + 5];
  sort(c, c + n);
  for (int i = 0; i < n; ++i)
    for (int j = n - 1; j >= 0; --j) {
      chkmax(f[j + 1], f[j] + c[i].a - (long long)c[i].b * j);
      chkmax(f[j], f[j] + c[i].a - (long long)c[i].b * c[i].k);
    }
  for (int i = 0; i <= n; ++i) cerr << i << ' ' << f[i] << endl;
  cout << *max_element(f, f + n + 1) << endl;
}
int main() {
  input();
  solve();
  return 0;
}
