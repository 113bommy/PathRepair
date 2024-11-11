#include <bits/stdc++.h>
const int MaxN = 30050;
const int MaxM = 2e5 + 50;
template <class t>
inline void read(t &s) {
  s = 0;
  register int f = 1;
  register char c = getchar();
  while (!isdigit(c)) {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (isdigit(c)) s = (s << 3) + (s << 1) + (c ^ 48), c = getchar();
  s *= f;
  return;
}
template <class t, class... A>
inline void read(t &x, A &...a) {
  read(x);
  read(a...);
}
template <class t>
inline void write(t x) {
  if (x < 0) putchar('-'), x = -x;
  int buf[21], top = 0;
  while (x) buf[++top] = x % 10, x /= 10;
  if (!top) buf[++top] = 0;
  while (top) putchar(buf[top--] ^ '0');
  return;
}
inline void setIn(std::string s) {
  freopen(s.c_str(), "r", stdin);
  return;
}
inline void setOut(std::string s) {
  freopen(s.c_str(), "w", stdout);
  return;
}
inline void setIO(std::string s = "") {
  setIn(s + ".in");
  setOut(s + ".out");
  return;
}
template <class t>
inline bool checkmin(t &x, t y) {
  if (x > y) {
    x = y;
    return 1;
  }
  return 0;
}
template <class t>
inline bool checkmax(t &x, t y) {
  if (x < y) {
    x = y;
    return 1;
  }
  return 0;
}
inline int lowbit(int x) { return x & (-x); }
char s[MaxM];
int cnt[26], f[MaxN];
inline void work() {
  int n, m, K;
  read(n, m, K);
  std::scanf("%s", s + 1);
  std::memset(cnt, 0, sizeof cnt);
  for (int i = 1; i <= K; ++i) ++cnt[s[i] - 'A'];
  register int ans = 2e9;
  for (int T = 0; T < 26; ++T) {
    std::memset(f, 0, (K + 1) * sizeof(int));
    f[0] = 1;
    for (int i = 0; i < 26; ++i)
      if (i ^ T)
        for (int j = K; j >= cnt[i]; --j) f[j] |= f[j - cnt[i]];
    for (int i = 0; i <= std::min(n, cnt[T]); ++i)
      if (f[n - i]) checkmin(ans, i * std::max(0, m - (K - cnt[T] - (n - i))));
    if (cnt[T] >= n && K - cnt[T] >= m) checkmin(ans, 0);
  }
  write(ans), std::puts("");
}
signed main(void) {
  int t;
  read(t);
  while (t--) work();
  return 0;
}
