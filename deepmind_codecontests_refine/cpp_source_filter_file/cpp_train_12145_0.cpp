#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e9 + 7;
const int N = 5e5 + 10;
int a[N];
int dp[2][N];
int minv[N];
int sum[N];
int n, k, p;
class BIT {
  int a[110];

 public:
  void init() { memset((a), (0x1f), sizeof(a)); }
  inline int lowbit(int x) { return x & -x; }
  void add(int x, int v) {
    x = p - x;
    while (x < 110) {
      a[x] = min(a[x], v);
      x += lowbit(x);
    }
  }
  int sum(int x) {
    x++;
    int ret = INF;
    while (x) {
      ret = min(ret, a[x]);
      x -= lowbit(x);
    }
    return ret;
  }
} b;
template <class T>
inline void readint(T &ret) {
  char c;
  ret = 0;
  while ((c = getchar()) < '0' || c > '9')
    ;
  while (c >= '0' && c <= '9') {
    ret = ret * 10 + (c - '0'), c = getchar();
  }
}
int main() {
  readint(n);
  readint(k);
  readint(p);
  int o = 0;
  for (int i = 1; i <= n; i++) {
    readint(a[i]);
    a[i] %= p;
    sum[i] = sum[i - 1] + a[i];
    dp[o][i] = (a[i] + dp[o][i - 1]) % p;
  }
  for (int i = 2; i <= k; i++) {
    o ^= 1;
    b.init();
    memset((dp[o]), (0x1f), sizeof(dp[o]));
    b.add(0, sum[i - 1]);
    int tot = 0;
    for (int j = i; j <= n; j++) {
      tot = (tot + a[j]);
      if (tot >= p) tot -= p;
      dp[o][j] = min(b.sum(tot) - p, b.sum(p)) + tot;
      int t = (p - tot);
      if (t == p) t = 0;
      b.add(t, dp[o ^ 1][j] + t);
    }
  }
  printf("%d\n", dp[o][n]);
  return 0;
}
