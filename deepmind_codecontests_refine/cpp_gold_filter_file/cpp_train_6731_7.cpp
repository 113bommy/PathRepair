#include <bits/stdc++.h>
using namespace std;
const int N = 105;
const int INF = numeric_limits<int>::max();
void read(int &x) {
  x = 0;
  char ch = getchar();
  int f = 1;
  while (!isdigit(ch)) (ch == '-' ? f = -1 : 0), ch = getchar();
  while (isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
  x *= f;
}
int ok, n, a[N], b[N], cnt[N];
int m;
int solve() {
  for (int l = 1; l <= n; ++l)
    for (int r = 1; r <= n; ++r) {
      memset(cnt, 0, sizeof(cnt));
      for (int i = l; i <= r; ++i) ++cnt[a[i]];
      int ok = 1;
      for (int i = 1; i <= m; ++i)
        if (cnt[i] != b[i]) ok = 0;
      if (ok) return 1;
    }
  return 0;
}
signed main() {
  read(n);
  read(m);
  for (int i = 1; i <= n; ++i) read(a[i]);
  for (int i = 1; i <= m; ++i) read(b[i]);
  return printf("%s", solve() ? "YES" : "NO"), 0;
}
