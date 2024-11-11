#include <bits/stdc++.h>
using namespace std;
void fre() {
  freopen("c://test//input.in", "r", stdin);
  freopen("c://test//output.out", "w", stdout);
}
template <class T1, class T2>
inline void gmax(T1 &a, T2 b) {
  if (b > a) a = b;
}
template <class T1, class T2>
inline void gmin(T1 &a, T2 b) {
  if (b < a) a = b;
}
const int N = 1e5 + 10, M = 0, Z = 1e9 + 7, inv = (Z + 1) / 2, inf = 0x3f3f3f3f;
template <class T1, class T2>
inline void gadd(T1 &a, T2 b) {
  a = (a + b) % Z;
}
int casenum, casei;
int n;
long long f[N];
vector<int> a[N];
int dep[N], from[N];
void dfs(int x, int fa) {
  dep[x] = 0;
  from[x] = -1;
  f[x] = 1;
  for (auto y : a[x])
    if (y != fa) {
      dfs(y, x);
      if (dep[y] + 1 > dep[x]) {
        dep[x] = dep[y] + 1;
        from[x] = y;
      } else if (dep[y] + 1 == dep[x]) {
        from[x] = inf;
      }
      f[x] = f[x] * f[y] % Z;
    }
  if (~from[x]) f[x] = f[x] * 2 % Z;
}
int ANS;
int main() {
  while (~scanf("%d", &n)) {
    for (int i = 1; i <= n; ++i) a[i].clear();
    for (int i = 1; i < n; ++i) {
      int x, y;
      scanf("%d%d", &x, &y);
      a[x].push_back(y);
      a[y].push_back(x);
    }
    ANS = 0;
    int ans1, ans2;
    for (int i = 1; i <= n; ++i)
      if (a[i].size() == 1) {
        dfs(i, 0);
        ans1 = f[i];
        ans2 = f[i] * inv % Z;
        break;
      }
    for (int i = 1; i <= n; ++i) {
      if (a[i].size() == 1)
        gadd(ANS, ans1);
      else
        gadd(ANS, ans2);
    }
    printf("%d\n", ANS);
  }
  return 0;
}
