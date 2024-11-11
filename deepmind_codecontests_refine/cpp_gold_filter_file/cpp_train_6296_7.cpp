#include <bits/stdc++.h>
using namespace std;
template <typename T1, typename T2>
inline T1 max(T1 a, T2 b) {
  return a < b ? b : a;
}
template <typename T1, typename T2>
inline T1 min(T1 a, T2 b) {
  return a < b ? a : b;
}
const char lf = '\n';
namespace ae86 {
const int bufl = 1 << 15;
char buf[bufl], *s = buf, *t = buf;
inline int fetch() {
  if (s == t) {
    t = (s = buf) + fread(buf, 1, bufl, stdin);
    if (s == t) return EOF;
  }
  return *s++;
}
inline int ty() {
  int a = 0, b = 1, c = fetch();
  while (!isdigit(c)) b ^= c == '-', c = fetch();
  while (isdigit(c)) a = a * 10 + c - 48, c = fetch();
  return b ? a : -a;
}
}  // namespace ae86
using ae86::ty;
const int _ = 100007, __ = 200007 + _;
vector<pair<int, int>> e[_];
int du[_] = {0}, ecnt = 0;
inline void adde(int a, int b) { du[a]++, e[a].emplace_back(b, ecnt); }
inline void addde(int a, int b) { ecnt++, adde(a, b), adde(b, a); }
int n, m, sig[_] = {0}, lsig = 0;
int nowe[_] = {0}, ed[__] = {0};
int temps = 0;
void dfs(int x) {
  while (nowe[x] < ((int)((e[x]).size()))) {
    auto [b, c] = e[x][nowe[x]++];
    if (ed[c]) continue;
    ed[c] = 1, dfs(b);
    temps++, cout << (temps & 1 ? x : b) << ' ' << (temps & 1 ? b : x) << lf;
  }
}
int main() {
  ios::sync_with_stdio(0), cout.tie(nullptr);
  n = ty(), m = ty();
  for (int i = 1, a, b; i <= m; i++) a = ty(), b = ty(), addde(a, b);
  for (int i = 1; i <= n; i++)
    if (du[i] & 1) sig[++lsig] = i;
  for (int i = 1; i + 1 <= lsig; i += 2) addde(sig[i], sig[i + 1]);
  if (ecnt & 1) addde(1, 1);
  cout << ecnt << lf;
  dfs(1);
  return 0;
}
