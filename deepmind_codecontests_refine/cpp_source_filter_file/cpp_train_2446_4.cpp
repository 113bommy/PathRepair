#include <bits/stdc++.h>
using namespace std;
const int MOD = 2520;
using LL = long long;
LL f[21][2530][50];
int nums[21];
int dis[50];
int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
int lcm(int x, int y) { return x * y / gcd(x, y); }
LL dfs(int pos, int premod, int prelcm, int limit) {
  if (!pos) return premod % prelcm == 0;
  if (!limit && f[pos][premod][dis[prelcm]] != -1)
    return f[pos][premod][dis[prelcm]];
  int up = limit ? nums[pos] : 9;
  LL res = 0;
  for (int i = 0; i <= up; ++i)
    res += dfs(pos - 1, (premod * 10 + i) % MOD, !i ? prelcm : lcm(prelcm, i),
               limit && i == up);
  return limit ? res : f[pos][premod][dis[prelcm]] = res;
}
void init() {
  memset(f, -1, sizeof f);
  int cnt = 0;
  for (int i = 1; i <= 2520; ++i)
    if (MOD % i == 0) {
      dis[i] = cnt++;
    }
}
LL cal(LL n) {
  int len = 0;
  while (n) {
    nums[++len] = n % 10;
    n /= 10;
  }
  return dfs(len, 0, 1, 1);
}
int main() {
  int t;
  scanf("%d", &t);
  init();
  while (t--) {
    LL l, r;
    cin >> l >> r;
    cout << cal(r) - cal(l - 1) << endl;
  }
  return 0;
}
