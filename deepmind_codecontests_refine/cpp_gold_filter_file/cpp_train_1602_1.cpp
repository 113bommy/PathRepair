#include <bits/stdc++.h>
using namespace std;
using namespace rel_ops;
const double pi = acos(-1.0);
const double eps = 1e-11;
const int inf = 0x7FFFFFFF;
template <class T>
inline bool checkmin(T &a, T b) {
  return b < a ? a = b, 1 : 0;
}
template <class T>
inline bool checkmax(T &a, T b) {
  return b > a ? a = b, 1 : 0;
}
template <class T>
inline T sqr(T x) {
  return x * x;
}
template <class T>
void show(T a, int n) {
  for (int i = 0; i < n; ++i) cout << a[i] << ' ';
  cout << endl;
}
template <class T>
void show(T a, int r, int l) {
  for (int i = 0; i < r; ++i) show(a[i], l);
  cout << endl;
}
int n, q, m;
const int N = 100005;
const long long mod = 1000000007;
int a[N];
int dp[N];
int nxt[N], pre[N];
int sum[1005];
int main() {
  while (cin >> n >> q >> m) {
    for (int i = 0; i < n; i++) {
      scanf("%d", a + i + 1);
      pre[i + 1] = i + 1;
      nxt[i + 1] = i + 1;
    }
    for (int i = 0; i < q; i++) {
      int u, v;
      scanf("%d%d", &u, &v);
      nxt[u] = v;
      pre[v] = u;
    }
    long long need = 0;
    for (int i = 1; i <= n; i++) {
      if (nxt[i] == i) {
        for (int j = i, c = 0;; j = pre[j], c++) {
          need += (long long)c * a[j];
          if (pre[j] == j) break;
          if (c > n) {
            puts("0");
            return 0;
          }
        }
      }
      for (int j = i, c = 0;; j = pre[j], c++) {
        sum[i] += a[j];
        if (pre[j] == j) break;
        if (c > n) {
          puts("0");
          return 0;
        }
      }
    }
    if (need > m)
      puts("0");
    else {
      m -= need;
      memset(dp, 0, sizeof(dp));
      dp[0] = 1;
      for (int i = 1; i <= n; i++) {
        for (int j = sum[i]; j <= m; j++)
          dp[j] = (dp[j] + dp[j - sum[i]]) % mod;
        ;
      }
      printf("%d\n", dp[m]);
    }
  }
  return 0;
}
