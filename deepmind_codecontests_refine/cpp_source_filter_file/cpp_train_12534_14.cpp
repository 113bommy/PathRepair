#include <bits/stdc++.h>
using namespace std;
int n, p[11], m, dd[11];
long long a[11];
vector<long long> s[11];
int dp[10000];
int getbit(int x, int i) { return (x / p[i - 1]) % 3; }
int upbit(int x, int i) { return x + p[i - 1]; }
void update(int &u, int x) {
  if (u == 0 || u > x) u = x;
}
int Count(int j, long long sum) {
  if (dd[j]) return 0;
  int x = 0;
  for (int i = 0; i <= (int)s[j].size() - 1; i++) {
    long long u = s[j][i];
    while (sum % u == 0) {
      x++;
      sum /= u;
    }
  }
  return x;
}
void Cal(int cur, int tt, long long sum, int x, int j) {
  if (cur > n) {
    update(dp[tt], x + Count(j, sum));
    return;
  }
  int k = getbit(tt, cur);
  Cal(cur + 1, tt, sum, x, j);
  if (k == 0 && sum % a[cur] == 0)
    Cal(cur + 1, upbit(tt, cur), sum / a[cur], x + 1, j);
}
int main() {
  scanf("%d", &n);
  p[0] = 1;
  for (int i = 1; i <= n; i++) p[i] = p[i - 1] * 3;
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  for (int i = 1; i <= n; i++) a[i] = -a[i];
  sort(a + 1, a + n + 1);
  for (int i = 1; i <= n; i++) a[i] = -a[i];
  for (int i = 1; i <= n; i++) {
    long long u = a[i];
    for (int j = 2; (long long)j * j <= a[i]; j++)
      if (u % j == 0) {
        s[i].push_back(j);
        while (u % j == 0) u /= j;
      }
    if (u > 1) s[i].push_back(u);
    if (a[i] == s[i][0]) dd[i] = 1;
  }
  int j = 0;
  for (int i = 1; i <= (1 << n) - 1; i++) {
    int u = 0, v = 0;
    for (int j = 1; j <= n; j++)
      if ((i & (1 << j - 1))) {
        u += p[j - 1];
        v++;
      }
    dp[u] = v + (v > 1);
  }
  for (int i = 1; i <= p[n] - 1; i++)
    if (dp[i] > 0) {
      j = 1;
      while (j <= n && getbit(i, j) != 1) j++;
      if (j > n) continue;
      m = i;
      Cal(1, upbit(i, j), a[j], dp[i], j);
    }
  cout << dp[p[n] - 1];
  return 0;
}
