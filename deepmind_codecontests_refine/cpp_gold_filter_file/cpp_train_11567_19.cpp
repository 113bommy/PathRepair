#include <bits/stdc++.h>
using namespace std;
long long f[5];
inline long long GetSi(long long x, long long de, long long num) {
  if (de < 0) return 0;
  if (!de) return num;
  if (num == 10000) return f[de];
  long long ans = 0;
  for (long long i = 0, pl = num; i <= num; ++i) {
    long long tmp = GetSi(x, de - 1, pl);
    x += tmp + 1;
    ans += tmp;
    pl = min(10000ll, x);
  }
  return ans + num;
}
inline void Dfs(long long x, long long de, long long num) {
  vector<long long> ans;
  for (long long i = 1, k = x, pl = num; i <= num; ++i) {
    k += GetSi(k, de - 1, pl);
    ans.push_back(k);
    ++k;
    pl = min(10000ll, k);
  }
  printf("%lld ", (long long)ans.size());
  for (long long i : ans) printf("%lld ", i);
  puts("");
  fflush(stdout);
  long long rst;
  scanf("%lld", &rst);
  if (rst < 0) exit(0);
  if (rst == 0)
    Dfs(x, de - 1, num);
  else
    Dfs(ans[rst - 1] + 1, de - 1, min(10000ll, ans[rst - 1] + 1));
}
signed main() {
  f[0] = 10000;
  for (long long i = 1; i < 4; ++i) f[i] = f[i - 1] * 10001 + 10000;
  Dfs(1, 4, 1);
  return 0;
}
