#include <bits/stdc++.h>
using namespace std;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const long long LINF = 0x3f3f3f3f3f3f3f3f;
const int N = 2e5 + 10, M = 100001;
inline long long read() {
  char ch = getchar();
  long long f = 1, x = 0;
  while (ch > '9' || ch < '0') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}
bool vis[N];
int tong[N], a[N];
int main() {
  int T = read();
  while (T--) {
    int n = read(), k = read(), x;
    for (int i = 1; i <= n; ++i) x = read(), tong[x] = i, vis[i] = 0;
    for (int i = 1; i <= k; ++i) a[i] = read();
    long long ans = 1;
    for (int i = n; i >= 1; --i) {
      int pos = tong[a[i]];
      vis[pos] = 1;
      int p = 0;
      if (pos < n && vis[pos + 1] == 0) ++p;
      if (pos > 1 && vis[pos - 1] == 0) ++p;
      ans = ans * p % MOD;
    }
    cout << ans << endl;
  }
  return 0;
}
