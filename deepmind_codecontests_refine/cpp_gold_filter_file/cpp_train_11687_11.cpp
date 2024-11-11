#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 9;
const int MOD = 1000000007;
int mod = 999998639;
inline long long qpow(long long b, long long e, long long m = MOD) {
  long long a = 1;
  for (; e; e >>= 1, b = b * b % m)
    if (e & 1) a = a * b % m;
  return a;
}
int d[maxn];
bool f[109][209];
int main() {
  int _;
  while (scanf("%d", &_) != EOF) {
    while (_--) {
      int n, k, l;
      scanf("%d%d%d", &n, &k, &l);
      for (int i = 1; i <= n; i++) {
        scanf("%d", &d[i]);
      }
      memset(f, false, sizeof(f));
      for (int j = 0; j < 2 * k; j++) {
        f[0][j] = true;
      }
      for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 2 * k; j++) {
          if (f[i][(j - 1 + 2 * k) % (2 * k)] ||
              f[i - 1][(j - 1 + 2 * k) % (2 * k)]) {
            int temp;
            if (j <= k)
              temp = j;
            else
              temp = 2 * k - j;
            if (temp + d[i] <= l) {
              f[i][j] = true;
            }
          }
        }
      }
      bool flag = false;
      for (int j = 0; j < 2 * k; j++) {
        if (f[n][j]) {
          flag = true;
          break;
        }
      }
      if (flag)
        printf("YES\n");
      else
        printf("NO\n");
    }
  }
}
