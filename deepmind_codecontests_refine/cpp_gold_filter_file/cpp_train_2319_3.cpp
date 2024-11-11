#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 5, mod = 998244353;
template <class o>
inline void qr(o &x) {
  x = 0;
  char c = getchar();
  int f = 1;
  while (c < '0' || c > '9') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    x = x * 10 + (c ^ 48);
    c = getchar();
  }
  x *= f;
}
template <class o>
void qw(o x) {
  if (x / 10) qw(x / 10);
  putchar(x % 10 + 48);
}
template <class o>
void pr1(o x) {
  if (x < 0) putchar('-'), x = -x;
  qw(x);
  putchar(' ');
}
template <class o>
void pr2(o x) {
  if (x < 0) putchar('-'), x = -x;
  qw(x);
  puts("");
}
inline int ksm(int a, int b = mod - 2) {
  int ans = 1;
  for (; b; b >>= 1, a = 1ll * a * a % mod)
    if (b & 1) ans = 1ll * ans * a % mod;
  return ans;
}
vector<int> p[N];
int ans[N], w[N], a[N];
void solve() {
  int n;
  qr(n);
  memset(ans, 0x3f, (n + 1) << 2);
  for (int i = 1; i <= n; ++i) {
    qr(a[i]);
    p[a[i]].push_back(i);
    w[i] = a[i];
  }
  sort(w + 1, w + n + 1);
  int m = unique(w + 1, w + n + 1) - (w + 1);
  for (int i = 1; i <= m; ++i) {
    int x = w[i], sum = max(1, p[x][0]);
    p[x].push_back(n + 1);
    for (int j = 1; j < p[x].size(); ++j) {
      sum = max(sum, p[x][j] - p[x][j - 1]);
    }
    ans[sum] = min(ans[sum], x);
  }
  for (int i = 1; i <= m; ++i) p[w[i]].clear();
  for (int i = 1; i <= n; ++i)
    ans[i] = min(ans[i], ans[i - 1]), pr1(ans[i] == 0x3f3f3f3f ? -1 : ans[i]);
  puts("");
}
int main() {
  int T;
  qr(T);
  while (T--) {
    solve();
  }
  return 0;
}
