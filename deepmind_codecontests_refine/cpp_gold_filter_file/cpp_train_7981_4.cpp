#include <bits/stdc++.h>
using namespace std;
void Open() {
  freopen("Input.txt", "r", stdin);
  freopen("Output.txt", "w", stdout);
}
long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a % b); }
void madesetprobblem() {}
int a, n, m, *x, *y;
long long dp[2006][2006];
long long ans(int c, int s) {
  if (c == a + 1) {
    return 0;
  }
  long long &ret = dp[c][s];
  if (~ret) return ret;
  int z = s;
  if (y[c] > 0) {
    if (s == a + 1) {
      s = c;
    } else if (y[c] < y[s]) {
      s = c;
    }
  }
  ret = 0;
  if (x[c] == 1 && s == a + 1) {
    return ret = 1e15;
  }
  if (x[c]) {
    ret = ans(c + 1, s) + y[s];
  } else
    ret = min(ans(c + 1, s) + y[s], ans(c + 1, a + 1));
  return ret;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  memset(dp, -1, sizeof dp);
  ;
  cin >> a >> n >> m;
  x = new int[a + 3];
  y = new int[a + 3];
  for (int i = 0; i < a + 3; i++) {
    x[i] = y[i] = 0;
  }
  int l, r;
  for (int i = 0; i < n; i++) {
    cin >> l >> r;
    for (int j = l; j < r; j++) {
      x[j] = 1;
    }
  }
  for (int j = 0; j < m; j++) {
    cin >> l >> r;
    if (y[l]) {
      y[l] = min(y[l], r);
    } else
      y[l] = r;
  }
  y[a + 1] = 0;
  long long z = ans(0, a + 1);
  if (z >= 1e15)
    cout << -1;
  else
    cout << z;
}
