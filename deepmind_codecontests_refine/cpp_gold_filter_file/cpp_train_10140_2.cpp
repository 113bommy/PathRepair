#include <bits/stdc++.h>
using namespace std;
map<pair<long long, long long>, pair<long long, long long> > dp;
long long sl[20];
void Init() {
  dp.clear();
  sl[0] = 1;
  for (int i = 1; i <= 18; i++) {
    sl[i] = sl[i - 1] * 10;
  }
  sl[19] = sl[18] + 1;
}
int divide(long long now, long long &x, long long &y) {
  y = 0;
  int len = 1;
  while (sl[len] <= now) len++;
  len--;
  long long tp = sl[len];
  x = now / tp;
  y = now - x * tp;
  return len;
}
pair<long long, long long> dfs(long long now, long long mxd) {
  pair<long long, long long> state = make_pair(now, mxd);
  if (dp.find(state) != dp.end()) {
    return dp[state];
  } else if (now <= 0) {
    return make_pair(0, 0);
  }
  pair<long long, long long> ans = make_pair(0, 0);
  long long x, y;
  while (now >= 10) {
    int len = divide(now, x, y);
    pair<long long, long long> next = dfs(y, max(mxd, x));
    ans.first += next.first;
    if (next.second > 0) {
      x--;
      y = sl[len] - next.second;
      now = x * sl[len] + y;
    } else {
      ans.first++;
      now = x * sl[len] - max(mxd, x);
    }
  }
  if (now > 0) {
    ans.first++;
    if (now < mxd) {
      ans.second = mxd - now;
    }
  }
  return dp[state] = ans;
}
int main() {
  Init();
  long long n;
  scanf("%I64d", &n);
  printf("%I64d\n", dfs(n, 0ll).first);
  return 0;
}
