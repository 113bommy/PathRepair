#include <bits/stdc++.h>
using namespace std;
const long long linf = 1e18 + 5;
const int mod = (int)1e9 + 7;
const int logN = 17;
const int inf = 1e9;
const int N = 2e3 + 5;
int n, m, x, y, z, a[N], w, upd[N][5], dp[N][N][2];
int f(int w, int mask, int c) {
  if (w == n + 1) return c;
  int &r = dp[w][mask][c];
  if (r != -1) return r;
  r = 0;
  if (c) return r = f(w + 1, mask, c) * (long long)(1 + !a[w]) % mod;
  if (a[w]) {
    mask = upd[mask][a[w] / 2];
    if (mask & (1 << m)) return r = f(w + 1, 0, 1);
    return r = f(w + 1, mask, c);
  }
  int temp = mask;
  mask = upd[temp][2];
  if (mask & (1 << m))
    r = (r + f(w + 1, 0, 1)) % mod;
  else
    r = (r + f(w + 1, mask, 0)) % mod;
  mask = upd[temp][1];
  if (mask & (1 << m))
    r = (r + f(w + 1, 0, 1)) % mod;
  else
    r = (r + f(w + 1, mask, 0)) % mod;
  return r;
}
int main() {
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  for (int i = 0; i <= (1 << m) - 1; i++) {
    for (int t = 1; t <= 2; t++) {
      stack<int> S;
      int mask = 0;
      for (int j = m; j >= 1; j--)
        if ((1 << j) & i) {
          S.push(j);
        }
      S.push(t);
      while (S.size() > 1) {
        int s1 = S.top();
        S.pop();
        int s2 = S.top();
        S.pop();
        if (s1 == s2)
          S.push(s1 + 1);
        else {
          S.push(s2);
          S.push(s1);
          break;
        }
      }
      int last = 0;
      while (S.size()) {
        if (S.top() < last) break;
        mask |= (1 << S.top());
        last = S.top();
        S.pop();
      }
      upd[i][t] = mask;
    }
  }
  memset(dp, -1, sizeof dp);
  cout << f(1, 0, 0) << '\n';
  return 0;
}
