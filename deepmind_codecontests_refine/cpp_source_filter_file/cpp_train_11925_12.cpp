#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e2 + 10;
const int MOD = 1e9 + 7;
long long qpow(long long a, long long b) {
  long long cnt = 1;
  while (b) {
    if (b & 1) cnt *= a;
    a *= a;
    b >>= 1;
  }
  return cnt;
}
long long len1, len2, n, m;
int vis[10];
long long dfs(int pos, long long hour, long long min) {
  if (pos >= len1 + len2) return 1;
  long long rnt = 0;
  if (pos < len1) {
    for (int i = 0; i <= 6; i++) {
      long long cur = hour + i * qpow(7, len1 - pos - 1);
      if (cur >= n || vis[i]) continue;
      vis[i] = 1;
      rnt += dfs(pos + 1, cur, min);
      vis[i] = 0;
    }
  } else {
    for (int i = 0; i <= 6; i++) {
      long long cur = min + i * qpow(7, len2 - (pos - len1) - 1);
      if (cur >= m || vis[i]) continue;
      vis[i] = 1;
      rnt += dfs(pos + 1, hour, cur);
      vis[i] = 0;
    }
  }
  return rnt;
}
int main() {
  ios::sync_with_stdio(false);
  cout.tie(NULL);
  cin >> n >> m;
  long long tmp = n;
  while (tmp) {
    len1++;
    tmp /= 7;
  }
  tmp = m;
  while (tmp) {
    len2++;
    tmp /= 7;
  }
  tmp = 7;
  while (n > tmp) tmp *= 7;
  if (n == tmp) len1--;
  tmp = 7;
  while (m > tmp) tmp *= 7;
  if (m == tmp) len1--;
  cout << dfs(0, 0, 0) << endl;
}
