#include <bits/stdc++.h>
using namespace std;
const int N = 18, sgn[] = {1, -1};
int n, l, a[N][N], cnt[1 << N], tag[1 << N];
long long int dp[N][1 << N], g[N + 1][1 << N], t[N + 1][1 << N], f[1 << N];
map<vector<int>, long long int> mp;
inline void input() {
  static char tmp[N];
  scanf("%d", &n), l = 1 << n;
  for (int i = 0; i < n; i++) {
    scanf("%s", tmp);
    for (int j = 0; j < n; j++) a[i][j] = tmp[j] - '0';
  }
}
inline void dot(long long int* a, long long int* b, long long int* c) {
  for (int i = 0; i < l; i++) c[i] = a[i] * b[i];
}
inline void FWT(long long int* t) {
  for (int i = 1; i < l; i <<= 1)
    for (int j = 0; j < l; j++)
      if (j & i) t[j] += t[j ^ i];
}
inline void IFWT(long long int* t) {
  for (int i = 1; i < l; i <<= 1)
    for (int j = 0; j < l; j++)
      if (j & i) t[j] -= t[j ^ i];
}
inline void init() {
  tag[0] = sgn[n & 1];
  for (int i = 1; i < l; i++)
    cnt[i] = cnt[i >> 1] + (i & 1), tag[i] = sgn[i & 1] * tag[i >> 1],
    t[0][i] = 1;
  for (int i = 0; i < n; i++) dp[i][1 << i] = 1;
  for (int i = 1; i < l; i++)
    for (int j = 0; j < n; j++) {
      g[cnt[i]][i] += dp[j][i];
      for (int k = 0; k < n; k++)
        if (!(i >> k & 1) && a[j][k]) dp[k][1 << k | i] += dp[j][i];
    }
  for (int i = 1; i <= n - 1; i++) FWT(g[i]);
}
inline void dfs(int p, int lim, int res) {
  static vector<int> now;
  if (!res) {
    long long int sum = 0;
    for (int i = 0; i < l; i++) sum += t[p][i] * tag[i];
    return void(mp[now] = sum);
  }
  for (int i = lim; i <= res; i++) {
    dot(t[p], g[i], t[p + 1]);
    now.push_back(i);
    dfs(p + 1, i, res - i);
    now.pop_back();
  }
}
long long int div(int x) {
  vector<int> now;
  int cnt = 1;
  for (int i = 0; i <= n - 2; i++)
    (x >> i & 1) && (now.push_back(cnt), cnt = 0), cnt++;
  return now.push_back(cnt), sort(now.begin(), now.end()), mp[now];
}
inline void work() {
  dfs(0, 1, n);
  for (int i = 0; i < l >> 1; i++) f[i] = div(i);
  IFWT(f), reverse(f, f + l / 2);
  for (int i = 0; i < l >> 1; i++) cout << f[i] << ' ';
}
int main() {
  input();
  init();
  work();
  return 0;
}
