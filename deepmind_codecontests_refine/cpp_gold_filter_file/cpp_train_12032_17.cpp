#include <bits/stdc++.h>
using namespace std;
const int maxn = 20, maxl = 16;
string trans = "0123456789abcdef";
long long k, C[maxn][maxn], dp[maxn][maxn], All[maxn];
int t, a[maxn], b[maxn];
long long Solve(int d, int x) {
  if (d == -1) return 1;
  if (x == 0) {
    if (t - b[x] >= d + 1) return 1;
    return 0;
  }
  long long& ret = dp[d][x];
  if (ret >= 0) return ret;
  ret = 0;
  for (int i = 0; i <= min(d + 1, t - b[x]); i++)
    ret += C[d + 1][i] * Solve(d - i, x - 1);
  return ret;
}
bool check(long long x) {
  memset(b, 0, sizeof(b));
  int len;
  for (int i = 0; i < 9; i++) {
    a[i] = x % 16;
    x /= 16;
    len = i;
    if (!x) break;
  }
  long long ret = len ? All[len - 1] : 0;
  for (int i = len; i >= 0; i--) {
    for (int j = (i == len ? 1 : 0); j < a[i]; j++) {
      b[j]++;
      if (b[j] <= t) {
        memset(dp, -1, sizeof(dp));
        ret += Solve(i - 1, 15);
      }
      b[j]--;
    }
    b[a[i]]++;
    if (b[a[i]] > t) break;
  }
  return ret < k;
}
long long getAll(int pos) {
  long long ret = 0;
  memset(b, 0, sizeof(b));
  for (int i = 1; i < 16; i++) {
    memset(dp, -1, sizeof(dp));
    b[i]++;
    ret += Solve(pos - 1, 15);
    b[i]--;
  }
  return ret;
}
int main() {
  scanf("%lld%d", &k, &t);
  for (int i = 0; i < maxn; i++) {
    C[i][0] = C[i][i] = 1;
    for (int j = 1; j < i; j++) C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
  }
  for (int i = 0; i < 9; i++) {
    All[i] = getAll(i);
    if (i) All[i] += All[i - 1];
  }
  long long l = 0, r = (1LL << 36) - 1;
  while (l <= r) {
    long long mid = (l + r) >> 1;
    if (check(mid))
      l = mid + 1;
    else
      r = mid - 1;
  }
  l--;
  vector<int> ans;
  ans.clear();
  while (l > 0) {
    ans.push_back(l % 16);
    l /= 16;
  }
  reverse(ans.begin(), ans.end());
  for (auto x : ans) printf("%c", trans[x]);
  puts("");
  return 0;
}
