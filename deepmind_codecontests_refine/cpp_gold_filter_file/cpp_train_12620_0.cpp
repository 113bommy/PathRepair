#include <bits/stdc++.h>
static char ibuf[1 << 20 | 1], obuf[1 << 20 | 1], *p1 = ibuf, *p2 = ibuf,
                                                  *p3 = obuf;
struct IO {
  inline char gc() {
    return p1 == p2 && (p2 = (p1 = ibuf) + fread(ibuf, 1, 1 << 20 | 1, stdin),
                        p1 == p2)
               ? EOF
               : *p1++;
  }
  inline void flush() { fwrite(obuf, 1, p3 - obuf, stdout); }
  template <typename T>
  inline IO operator>>(T &n) {
    n = 0;
    bool s = 0;
    char c = gc();
    while (c < '0' || c > '9') s |= c == '-', c = gc();
    while (c >= '0' && c <= '9') n = n * 10 + (c ^ 48), c = gc();
    if (s) n = -n;
    return *this;
  }
  inline IO operator<<(char n) {
    if (p3 - obuf == (1 << 20 | 1))
      fwrite(obuf, 1, 1 << 20 | 1, stdout), p3 = obuf;
    *p3++ = n;
    return *this;
  }
  template <typename T>
  inline IO operator<<(T n) {
    static int stk[41];
    int top = 0;
    if (n < 0) *this << '-', n = -n;
    do stk[top++] = n % 10 + 48;
    while (n /= 10);
    while (top) *this << char(stk[--top]);
    return *this;
  }
} cin, cout;
using ll = long long;
int N, m[1003], z[1003], ans[1003];
ll tota;
void solve(int mid) {
  ll tot = m[mid];
  z[mid] = m[mid];
  for (int i = mid - 1; i; --i) z[i] = std::min(m[i], z[i + 1]), tot += z[i];
  for (int i = mid + 1; i <= N; ++i)
    z[i] = std::min(m[i], z[i - 1]), tot += z[i];
  if (tot > tota) {
    tota = tot;
    memcpy(ans + 1, z + 1, sizeof(int) * N);
  }
}
int main() {
  cin >> N;
  for (int i = 1; i <= N; ++i) cin >> m[i];
  for (int i = 1; i <= N; ++i) solve(i);
  for (int i = 1; i <= N; ++i) cout << ans[i] << ' ';
  cout.flush();
  return 0;
}
