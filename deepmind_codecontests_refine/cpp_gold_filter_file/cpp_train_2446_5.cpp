#include <bits/stdc++.h>
using namespace std;
const int mod = 2520;
int dig[20];
long long dp[20][2520][50];
int myhash[2521];
void init() {
  int cnt = 0;
  for (int i = 1; i <= 2520; ++i) {
    if (2520 % i == 0) {
      myhash[i] = ++cnt;
    }
  }
}
int gcd(int a, int b) {
  if (a > b) {
    swap(a, b);
  }
  return a == 0 ? b : gcd(b % a, a);
}
int lcm(int a, int b) { return a * b / gcd(a, b); }
long long dfs(int len, int pre, int prelcm, int flag) {
  if (len < 0) {
    return pre % prelcm == 0;
  }
  if (!flag && dp[len][pre][myhash[prelcm]] != -1) {
    return dp[len][pre][myhash[prelcm]];
  }
  int end = flag ? dig[len] : 9;
  long long ans = 0;
  int testprelcm;
  int testpre;
  for (int i = 0; i <= end; ++i) {
    if (i != 0) {
      testprelcm = lcm(prelcm, i);
    } else {
      testprelcm = prelcm;
    }
    testpre = (pre * 10 + i) % mod;
    ans += dfs(len - 1, testpre, testprelcm, flag && i == end);
  }
  if (!flag) {
    dp[len][pre][myhash[prelcm]] = ans;
  }
  return ans;
}
long long solve(long long x) {
  long long t = x;
  int cnt = 0;
  while (t) {
    dig[cnt++] = t % 10;
    t = t / 10;
  }
  return dfs(cnt - 1, 0, 1, 1);
}
int main() {
  int T;
  scanf("%d", &T);
  memset(dp, -1, sizeof(dp));
  init();
  while (T--) {
    long long l, r;
    cin >> l >> r;
    cout << solve(r) - solve(l - 1) << endl;
  }
  return 0;
}
