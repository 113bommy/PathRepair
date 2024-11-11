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
inline long long ty() {
  long long a = 0;
  int b = 1, c = fetch();
  while (!isdigit(c)) b ^= c == '-', c = fetch();
  while (isdigit(c)) a = a * 10 + c - 48, c = fetch();
  return b ? a : -a;
}
}  // namespace ae86
using ae86::ty;
const int mo = 1000000007;
template <typename T1, typename T2>
inline T1 ad(T1 &a, T2 b) {
  return a = a + b >= mo ? a + b - mo : a + b;
}
template <typename T1, typename T2>
inline T1 dl(T1 &a, T2 b) {
  return a = a >= b ? a - b : a - b + mo;
}
template <typename T1, typename T2>
inline T1 add(T1 a, T2 b) {
  return a + b >= mo ? a + b - mo : a + b;
}
template <typename T1, typename T2>
inline T1 del(T1 a, T2 b) {
  return a >= b ? a - b : a - b + mo;
}
const int L = 500, N = L + L, _ = N + 7, __ = _ + _;
const int go[2][8] = {{1, 1, -1, -1, 2, 2, -2, -2},
                      {2, -2, 2, -2, 1, -1, 1, -1}};
int mp[__][__] = {0}, tim[__][__] = {0};
long long ans[__];
void bfs(int lim) {
  queue<pair<int, int>> q;
  q.emplace(_, _), tim[_][_] = 1;
  while (!q.empty()) {
    auto [x, y] = q.front();
    q.pop();
    ans[tim[x][y]]++;
    if (tim[x][y] >= lim) continue;
    for (int k = 0; k < 8; k++) {
      int xx = x + go[0][k], yy = y + go[1][k];
      if (xx < 0 || xx >= __ || yy < 0 || yy >= __ || mp[xx][yy] || tim[xx][yy])
        continue;
      tim[xx][yy] = tim[x][y] + 1, q.emplace(xx, yy);
    }
  }
}
int n;
long long m;
int main() {
  ios::sync_with_stdio(0), cout.tie(nullptr);
  m = ty(), n = ty();
  for (int i = 1, a, b; i <= n; i++) a = ty() + _, b = ty() + _, mp[a][b] = 1;
  bfs(L);
  long long sans = 0;
  if (m < L) {
    for (int i = 1; i <= m + 1; i++) ad(sans, ans[i]);
  } else {
    m = (m - L + 2) % mo;
    for (int i = 0; i < L; i++) ad(sans, ans[i]);
    sans = add(add(sans, ans[L] * m % mo),
               (m * (m - 1) / 2) % mo * del(ans[L], ans[L - 1]));
  }
  cout << sans << lf;
  return 0;
}
