#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10, mod = 1e9 + 7;
int n, K, ans, cnt;
char s[5];
struct DSU {
  int fa[N];
  bool mark[N];
  int getfa(int x) { return fa[x] == -1 ? x : fa[x] = getfa(fa[x]); }
  bool merge(int x, int y) {
    int fx = getfa(x), fy = getfa(y);
    if (getfa(x ^ 1) == fy || getfa(y ^ 1) == fx) return 0;
    if (fx != fy) fa[fx] = fy;
    return 1;
  }
  bool Set(int l, int r, int c) {
    if (!c)
      return merge(l * 2, r * 2) && merge(l * 2 + 1, r * 2 + 1);
    else
      return merge(l * 2 + 1, r * 2) && merge(l * 2, r * 2 + 1);
  }
} T;
int qpow(int a, int b) {
  int ret = 1;
  for (; b; b >>= 1) {
    if (b & 1) ret = 1ll * ret * a % mod;
    a = 1ll * a * a % mod;
  }
  return ret;
}
int main() {
  cin >> n >> K;
  memset(T.fa, -1, sizeof(T.fa));
  for (int i = 1; i <= K; i++) {
    int x, y;
    scanf("%d%d%s", &x, &y, s + 1);
    --x, --y;
    int l = x - y, r = x + y;
    if (l < 0) l = -l;
    if (r > n - 1) r = (n - 1) * 2 - r;
    if (!T.Set(l, r + 2, s[0] == 'o')) {
      return puts("0"), 0;
    }
  }
  for (int i = 0; i <= n * 2 + 4; i++) ans += (T.getfa(i) == i);
  printf("%d\n", qpow(2, ans / 2 - 2));
  return 0;
}
