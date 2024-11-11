#include <bits/stdc++.h>
using namespace std;
template <class T>
inline T& RD(T& x) {
  char c;
  for (c = getchar(); c < '0'; c = getchar())
    ;
  x = c - '0';
  for (c = getchar(); '0' <= c && c <= '9'; c = getchar()) x = x * 10 + c - '0';
  return x;
}
const int inf = 0x3f3f3f3f;
const int maxn = 13005;
const int mod = 1e9 + 7;
int a[maxn];
int aa[maxn];
bool b[maxn][maxn];
int cnt;
int n, k;
void dfs(int t, int x, int y) {
  if (b[x][y]) return;
  b[x][y] = true;
  cnt++;
  if (!t || y > n) return;
  if (a[x] && aa[y]) dfs(t - 1, y + 1, y + 2);
  if (aa[y] && a[x] != 100) dfs(t - 1, y, y + 1);
  if (a[x] && aa[y] != 100) dfs(t - 1, x, y + 1);
}
int main() {
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
  }
  memset(aa, 0, sizeof(aa));
  for (int i = n; i >= 1; i--) {
    aa[i] = max(aa[i + 1], a[i]);
  }
  cnt = 0;
  memset(b, false, sizeof(b));
  dfs(k, 1, 2);
  printf("%d\n", cnt);
}
