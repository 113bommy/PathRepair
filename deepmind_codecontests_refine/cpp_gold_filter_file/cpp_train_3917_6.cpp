#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
long long read() {
  int f = 1;
  long long tmp = 0;
  char ch = getchar();
  while (ch != '-' && (ch < '0' || ch > '9')) ch = getchar();
  if (ch == '-') f = -1, ch = getchar();
  while (ch >= '0' && ch <= '9') tmp = tmp * 10 + ch - '0', ch = getchar();
  return f * tmp;
}
int n, fa[200005], size[200005];
bool loop[200005], cycle[200005];
int find(int x) {
  if (fa[x] == x) return x;
  fa[x] = find(fa[x]);
  return fa[x];
}
int main() {
  n = read();
  for (int i = 1; i <= 2 * n; i++) fa[i] = i, size[i] = 1;
  for (int i = 1; i <= n; i++) {
    int x = read(), y = read();
    if (x == y) loop[find(x)] = 1;
    int rx = find(x), ry = find(y);
    if (rx != ry) {
      fa[rx] = ry;
      size[ry] += size[rx];
      loop[ry] |= loop[rx];
    } else
      cycle[rx] = 1;
  }
  long long ans = 1;
  for (int i = 1; i <= 2 * n; i++) {
    if (find(i) == i) {
      if (loop[i]) continue;
      if (cycle[i])
        ans = ans * 2 % mod;
      else
        ans = ans * size[i] % mod;
    }
  }
  cout << ans << endl;
  return 0;
}
