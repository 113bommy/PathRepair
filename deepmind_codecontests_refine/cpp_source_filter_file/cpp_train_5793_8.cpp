#include <bits/stdc++.h>
using namespace std;
const int N = 23;
const int mod = 1e9 + 7;
int n, m;
int bs[N];
int ans, res;
int anslen, reslen;
int change[N][N];
void upd() {
  if (reslen < anslen || ans == 0) ans = res, anslen = reslen;
}
void dfs(int i) {
  for (int j = i; j <= n - 1; j++) {
    if (bs[j] == (1 << n) - 1 - (1 << j)) {
      res ^= (1 << (j + 1));
      upd();
      res ^= (1 << (j + 1));
      return;
    }
  }
  if (i >= n) return;
  dfs(i + 1);
  int t = bs[i];
  t += 1 << i;
  int head = 0, tail = 0;
  {
    int tmp = t;
    while (tmp) {
      int pos = __builtin_ctz(tmp);
      change[i][tail++] = bs[pos];
      bs[pos] |= t - (1 << pos);
      tmp -= tmp & -tmp;
    }
  }
  res ^= 1 << (i + 1);
  reslen++;
  dfs(i + 1);
  {
    int tmp = t;
    while (tmp) {
      int pos = __builtin_ctz(tmp);
      bs[pos] = change[i][head++];
      tmp -= tmp & -tmp;
    }
  }
  res ^= 1 << (i + 1);
  reslen--;
}
int main() {
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    bs[u] ^= 1 << v;
    bs[v] ^= 1 << u;
  }
  int f = 1;
  for (int i = 0; i <= n - 1; i++)
    if (bs[i] != (1 << n) - 1 - (1 << i)) {
      f = 0;
      break;
    }
  if (f || n == 1) {
    cout << 0 << endl;
    return 0;
  }
  dfs(0);
  cout << anslen << endl;
  cout << __builtin_ctz(ans);
  ans -= ans & -ans;
  while (ans) {
    cout << ' ' << __builtin_ctz(ans);
    ans -= ans & -ans;
  }
}
