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
int n;
vector<int> g[100010];
double p1[100010], p2[100010];
double ans;
int s[100010];
void dfs(int u, int fa) {
  s[u] = 1;
  for (int v : g[u])
    if (v != fa) {
      dfs(v, u);
      p1[u] += p1[v];
      s[u] += s[v];
      ans += p1[v] * s[v] * p2[u];
    }
  ans += (1 - p1[u]) * (n - s[u]) * p2[u];
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i < n; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    g[u].push_back(v);
    g[v].push_back(u);
  }
  double s1 = 0, s2 = 0;
  for (int i = 1; i <= n; i++)
    scanf("%lf%lf", p1 + i, p2 + i), s1 += p1[i], s2 += p2[i];
  for (int i = 1; i <= n; i++) p1[i] /= s1, p2[i] /= s2;
  dfs(1, 0);
  printf("%.10lf\n", ans);
  return 0;
}
