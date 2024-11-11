#include <bits/stdc++.h>
using namespace std;
template <typename T, typename U>
inline void chkmax(T& x, U y) {
  if (x < y) x = y;
}
template <typename T, typename U>
inline void chkmin(T& x, U y) {
  if (y < x) x = y;
}
const int MAXN = 2222;
int f[MAXN];
inline int get(int u) { return f[u] == 0 ? u : f[u] = get(f[u]); }
int main() {
  int n, m;
  cin >> n >> m;
  if (m >= n) {
    puts("no");
    return 0;
  }
  for (int i = 0; i < m; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    u = get(u), v = get(v);
    if (u != v) {
      f[u] = v;
    } else {
      puts("no");
      return 0;
    }
  }
  puts("yes");
  return 0;
}
