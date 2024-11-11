#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
vector<int> kmppre(string& t) {
  vector<int> r(t.size() + 1);
  r[0] = -1;
  int j = -1;
  for (int i = 0, qwerty = t.size(); i < qwerty; i++) {
    while (j >= 0 && t[i] != t[j]) j = r[j];
    r[i + 1] = ++j;
  }
  return r;
}
const int N = 45;
int n, m;
string s;
vector<int> r;
int can[N];
long long add(long long a, long long b) {
  a += b;
  if (a >= MOD) a -= MOD;
  return a;
}
long long mult(long long a, long long b) { return (a * b) % MOD; }
long long be(long long b, long long e) {
  long long r = 1;
  while (e)
    if (e & 1)
      r = (r * b) % MOD, e ^= 1;
    else
      b = (b * b) % MOD, e >>= 1;
  return r;
}
long long dp[N][N];
long long f(int i, int j) {
  long long& v = dp[i][j];
  if (v != -1) return v;
  if (i == 0) return v = can[j];
  if (j == n) return v = 0;
  v = 0;
  int j0 = j;
  while (j0 >= 0 && '0' != s[j0]) j0 = r[j0];
  j0++;
  v = add(v, f(i - 1, j0));
  int j1 = j;
  while (j1 >= 0 && '1' != s[j1]) j1 = r[j1];
  j1++;
  v = add(v, f(i - 1, j1));
  return v;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  memset((dp), (-1), sizeof(dp));
  cin >> m >> s;
  n = ((int)(s).size());
  r = kmppre(s);
  for (int x = 0, qwerty = n; x < qwerty; x++) {
    int j = x;
    can[x] = 1;
    for (int y = 0, qwerty = n - 1; y < qwerty; y++) {
      while (j >= 0 && s[y] != s[j]) j = r[j];
      if (++j == n) {
        can[x] = 0;
        break;
      }
    }
  }
  long long ans = 0;
  for (int x = 0, qwerty = m; x < qwerty; x++) {
    if (x + n <= m) {
      long long cnt = f(x, 0);
      ans = add(ans, mult(cnt, be(2, m - (x + n))));
    } else {
      int j = 0;
      for (int y = n - (x + n - m); y < n; y++) {
        while (j >= 0 && s[y] != s[j]) j = r[j];
        j++;
      }
      long long cnt = f(m - n, j);
      ans = add(ans, cnt);
    }
  }
  cout << ans << "\n";
}
