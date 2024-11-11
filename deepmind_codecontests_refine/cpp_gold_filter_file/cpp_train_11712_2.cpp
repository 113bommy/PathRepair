#include <bits/stdc++.h>
using namespace std;
const int inf = 0x0f0f0f0f;
template <class S, class T>
inline pair<S, T> MP(S a, T b) {
  return make_pair(a, b);
}
template <class T>
inline auto LX(T &X) -> decltype((X.first)) {
  return X.first;
}
template <class T>
inline auto LX(const T &X) -> const decltype((X.first)) {
  return X.first;
}
template <class T>
inline auto RX(T &X) -> decltype((X.second)) {
  return X.second;
}
template <class T>
inline auto RX(const T &X) -> const decltype((X.second)) {
  return X.second;
}
template <class T>
inline void RST(T &a) {
  memset(a, 0, sizeof(a));
}
template <class T>
inline void RST1(T &a) {
  memset(a, -1, sizeof(a));
}
template <class T>
inline void SINF(T &a) {
  memset(a, 0x0f, sizeof(a));
}
template <class S, class T>
inline void RST(S &a, T b) {
  fill((T *)a, (T *)a + (sizeof(a) / sizeof(b)), b);
}
template <class T>
inline void CLR(T &a) {
  a.clear();
}
template <class S, class T>
inline void CPY(S &a, T &b) {
  memcpy(a, b, sizeof(a));
}
template <class S, class T>
inline bool chkmin(S &a, T b) {
  return b < a ? a = b, 1 : 0;
}
template <class S, class T>
inline bool chkmax(S &a, T b) {
  return a < b ? a = b, 1 : 0;
}
template <class T>
inline T sqr(T x) {
  return x * x;
}
template <class T>
inline int SZ(T &a) {
  return (int)(a.size());
}
template <class T>
inline bool EPT(T &a) {
  return a.empty();
}
template <class T>
inline auto FRT(T &a) -> decltype((a.front())) {
  return a.front();
}
template <class T>
inline auto FRT(const T &a) -> const decltype((a.front())) {
  return a.front();
}
template <class T>
inline auto BK(T &a) -> decltype(a.back()) & {
  return a.back();
}
template <class T>
inline auto BK(const T &a) -> const decltype((a.back())) {
  return a.back();
}
template <class T>
inline auto TOP(T &a) -> decltype((a.top())) {
  return a.top();
}
template <class T>
inline auto TOP(const T &a) -> const decltype((a.top())) {
  return a.top();
}
int n, m, f[1010], g[1010], cnt;
char buf[1010];
double ans;
void solve(int *c, int n, int m) {
  int s = 0;
  for (int i = 1; i <= n; i++)
    if (c[i]) {
      s += c[i] - 1, ans += (double)s * (m - c[i]);
      if (!c[i + 1] || c[i + 1] < c[i]) s = 0;
    }
  s = 0;
  for (int i = 1; i <= n; i++)
    if (c[i]) {
      ans += (double)s * (c[i] - 1);
      s += m - c[i];
      if (!c[i + 1] || c[i + 1] > c[i]) s = 0;
    }
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) {
    scanf("%s", buf + 1);
    for (int j = 1; j <= m; j++)
      if (buf[j] == 'X') f[i] = j, g[j] = i, cnt++;
  }
  solve(f, n, m);
  solve(g, m, n);
  ans *= 2;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= i; j++)
      ans += 1. * (m - (f[i] ? 1 : 0)) * (m - (f[j] ? 1 : 0)) * (i - j);
  for (int i = 1; i <= m; i++)
    for (int j = 1; j <= i; j++)
      ans += 1. * (n - (g[i] ? 1 : 0)) * (n - (g[j] ? 1 : 0)) * (i - j);
  ans *= 2;
  ans /= sqr((double)n * m - cnt);
  printf("%.10lf\n", ans);
  return 0;
}
