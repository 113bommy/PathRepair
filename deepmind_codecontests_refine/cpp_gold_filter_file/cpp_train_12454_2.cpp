#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const long long INFF = 0x3f3f3f3f3f3f3f3fll;
const long long M = 1e9 + 7;
const long long maxn = 1e6 + 7;
const double eps = 0.00000001;
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
template <typename T>
inline T abs(T a) {
  return a > 0 ? a : -a;
}
template <typename T>
inline T powMM(T a, T b) {
  T ret = 1;
  for (; b; b >>= 1ll, a = a * a % M)
    if (b & 1) ret = 1ll * ret * a % M;
  return ret;
}
int i, j;
int n, m, k;
int VAL[maxn];
vector<long long> val[maxn], sum[maxn];
int main() {
  scanf("%d%d", &n, &m);
  val[1].push_back(0);
  sum[1].push_back(0);
  for (i = 2; i <= n; i++) {
    scanf("%d", &VAL[i]);
    long long now = 0;
    for (j = i; j; now += VAL[j], j /= 2) {
      val[j].push_back(now);
      sum[j].push_back(0);
    }
  }
  for (i = 1; i <= n; i++) {
    sort(val[i].begin(), val[i].end());
    sum[i][0] = val[i][0];
    for (j = 1; j < sum[i].size(); j++) sum[i][j] = val[i][j] + sum[i][j - 1];
  }
  while (m--) {
    int x;
    long long len;
    scanf("%d%I64d", &x, &len);
    long long ans = 0, pre = 0, prelen;
    for (; x && len > 0; len -= VAL[x], pre = x, prelen = VAL[x], x /= 2) {
      int pos =
          upper_bound(val[x].begin(), val[x].end(), len) - val[x].begin() - 1;
      ans += (pos + 1) * len - sum[x][pos];
      if (pre && prelen < len) {
        int thisnum =
            upper_bound(val[pre].begin(), val[pre].end(), len - prelen) -
            val[pre].begin() - 1;
        ans -= (thisnum + 1) * (len - prelen) - sum[pre][thisnum];
      }
    }
    printf("%I64d\n", ans);
  }
}
