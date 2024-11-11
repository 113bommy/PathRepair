#include <bits/stdc++.h>
using namespace std;
void MAIN();
int main() {
  MAIN();
  return 0;
}
const long long N = 1e5 + 1, mod = 1e9 + 7;
int n, m, dp[N][2];
pair<int, int> riki[N];
struct fwt {
  long long bit[N];
  void upd(int i, long long val) {
    for (; i < N; i += i & -i) {
      bit[i] += val;
    }
  }
  long long get(int i) {
    long long result = 0;
    for (; i > 0; i &= i - 1) {
      result += bit[i];
    }
    return result;
  }
} fwt1, fwt2, fwt3;
void MAIN() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    int val;
    scanf("%d", &val);
    riki[i] = pair<int, int>(val, i);
  }
  sort(riki + 1, riki + n + 1);
  long long ans = 0;
  for (int i = n; i >= 1; --i) {
    ans += fwt2.get(riki[i].second);
    fwt2.upd(riki[i].second, fwt1.get(riki[i].second));
    fwt1.upd(riki[i].second, 1);
  }
  printf("%lld", ans);
}
