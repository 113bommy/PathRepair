#include <bits/stdc++.h>
using namespace std;
map<pair<long long, long long>, int> dp;
long long n;
long long ksm(long long a, long long p) {
  if (p == 0) {
    return 1;
  }
  long long t = ksm(a, p / 2);
  t = t * t;
  if (p % 2) {
    t = t * a;
  }
  return t;
}
int dfs(long long a, long long b) {
  if (dp.count(make_pair(a, b))) {
    return dp[make_pair(a, b)];
  }
  if (ksm(a, b) >= n) {
    return dp[make_pair(a, b)] = 0;
  }
  if (a == 1 && ksm(2, b) >= n) {
    return dp[make_pair(a, b)] = 1;
  }
  if (b == 1 && ksm(a, 2) >= n) {
    if (a % 2 == n % 2) {
      return dp[make_pair(a, b)] = 0;
    } else {
      return dp[make_pair(a, b)] = 2;
    }
  }
  if (dfs(a + 1, b) == 0 || dfs(a, b + 1) == 0) {
    return dp[make_pair(a, b)] = 2;
  } else {
    return dp[make_pair(a, b)] = 0;
  }
}
long long a, b;
int main() {
  scanf("%lld%lld%lld", &a, &b, &n);
  int res = dfs(a, b);
  if (res == 0) {
    printf("Masha\n");
  } else if (res == 1) {
    printf("Missing\n");
  } else {
    printf("Stas\n");
  }
  return 0;
}
