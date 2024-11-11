#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline bool chkmax(T &a, const T &b) {
  return a < b ? a = b, 1 : 0;
}
template <typename T>
inline bool chkmin(T &a, const T &b) {
  return a > b ? a = b, 1 : 0;
}
template <typename T>
inline T read() {
  T sum = 0, fg = 1;
  char c = getchar();
  for (; !isdigit(c); c = getchar())
    if (c == '-') fg = -1;
  for (; isdigit(c); c = getchar()) sum = (sum << 3) + (sum << 1) + (c ^ 0x30);
  return fg * sum;
}
long long n, ans;
int main() {
  n = read<long long>() - 1;
  for (int i = 0, e = 31 - __builtin_clz(n); i <= e; i++) {
    int t = n & 1;
    n >>= 1;
    ans += (1LL << i) * (n + t);
  }
  cout << ans << endl;
  return 0;
}
