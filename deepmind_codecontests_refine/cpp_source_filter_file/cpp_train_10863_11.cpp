#include <bits/stdc++.h>
using namespace std;
inline void err(istringstream *iss) {}
template <typename T, typename... Args>
void err(istringstream *iss, const T &$val, const Args &...args) {
  string $name;
  *iss >> $name;
  if ($name.back() == ',') $name.pop_back();
  cout << $name << " = " << $val << "; ", err(iss, args...);
}
using ll = long long;
using ull = unsigned long long;
using ld = long double;
int n, m, K, T, Q, cn;
char a[200005], b[200005];
ll cnt[130], tot;
double ans, dp[200005];
int main() {
  cin.tie(NULL);
  scanf("%d%s%s", &n, a, b);
  ll cur = 0;
  for (int i = n - 1; i >= 0; i--) {
    cnt[b[i]] += n - i;
    cur += n - i, tot += cur;
    dp[i] = dp[i + 1] * (cur - n + i) / cur + cnt[a[i]] * 1.0 / cur,
    ans += dp[i] * cur;
  }
  memset(cnt, 0, sizeof(cnt)), memset(dp, 0, sizeof(dp));
  cur = 0;
  for (int i = n - 1; i >= 0; i--) {
    if (i < n - 1)
      dp[i] = dp[i + 1] * (cur - n + i) / cur + cnt[b[i]] * 1.0 / cur,
      ans += dp[i] * cur;
    cnt[a[i]] += n - i;
    tot += cur, cur += n - i;
  }
  printf("%.9f\n", ans / tot);
  return 0;
}
