#include <bits/stdc++.h>
#pragma GCC optimize(2)
#pragma G++ optimize(2)
#pragma comment(linker, "/STACK:102400000,102400000")
using namespace std;
long long rd() {
  long long x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}
const int inf = 0x3f;
const int maxn = 4e5 + 10;
int a[maxn];
long long f[1 << 20];
long long cost[21][21], sum[21];
int n, mx;
int main() {
  while (cin >> n) {
    memset(cost, 0, sizeof(cost));
    memset(sum, 0, sizeof(sum));
    memset(f, inf, sizeof(f));
    f[0] = 0;
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
      for (int j = 1; j <= 20; ++j) {
        cost[a[i]][j] += sum[j];
      }
      sum[a[i]]++;
    }
    mx = (1 << 20) - 1;
    for (int i = 1; i <= mx; i++) {
      for (int j = 0; j < 20; j++) {
        if (!((i >> j) & 1)) continue;
        long long t = 0;
        for (int k = 0; k < 20; k++) {
          if ((i >> k) & 1) continue;
          t += cost[j + 1][k + 1];
        }
        f[i] = min(f[i], f[i ^ (1 << j)] + t);
      }
    }
    cout << f[mx] << endl;
  }
}
