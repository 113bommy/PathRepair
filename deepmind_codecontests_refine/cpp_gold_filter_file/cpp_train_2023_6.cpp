#include <bits/stdc++.h>
using namespace std;
string s;
const int mn = 1000009;
int dp[mn][4][4];
bool visit[mn][4][4];
int low[4][4] = {{0, 0, 0, 0}, {3, 3, -1, 0}, {-1, -1, -1, 3}, {-1, 0, 0, 0}};
int hiw[4][4] = {{1, 1, 1, 1}, {3, 3, -1, 1}, {-1, -1, -1, 3}, {-1, 3, 3, 3}};
const int mod = 1e9 + 7;
int ma(char c) {
  if (c == '?') return 4;
  if (c == '*') return 3;
  return c - '0';
}
bool vad(int a, int b, int c) {
  if (b == 0) {
    if (a == 2 || c == 2 || a == 3 || c == 3) return false;
  } else if (b == 1) {
    if (a == 2 || c == 2) return false;
    if (a == 4 || c == 4) return true;
    if ((a == 3) == (c == 3)) return false;
  } else if (b == 2) {
    if (a < 3 || c < 3) return false;
    if (a > 4 || c > 4) return false;
  } else if (b == 3) {
    if (a == 0 || c == 0) return false;
  }
  return true;
}
bool valid(int *p) {
  int lo = 0, hi = 0;
  for (int i = 1; i < 4; i++) {
    if (!vad(p[i - 1], p[i], p[i + 1])) return false;
  }
  return true;
}
int f(int x, int p0, int p1) {
  if (x == s.size()) return 1;
  if (visit[x][p0][p1]) return dp[x][p0][p1];
  int res = 0;
  int lo = 0, hi = 3;
  if (s[x] != '?') hi = lo = ma(s[x]);
  int b1, b2, b3;
  b1 = (x - 3 >= 0 ? ma(s[x - 3]) : 5);
  b2 = (x + 1 >= s.size() ? 5 : ma(s[x + 1]));
  b3 = (x + 2 >= s.size() ? 5 : ma(s[x + 2]));
  for (int i = lo; i <= hi; i++) {
    int a[6] = {b1, p1, p0, i, b2, b3};
    if (!valid(&a[0])) continue;
    res = (res + f(x + 1, i, p0)) % mod;
  }
  visit[x][p0][p1] = 1;
  return dp[x][p0][p1] = res;
}
int main() {
  cin >> s;
  int res = 0;
  res = (res + f(0, 5, 5)) % mod;
  cout << res << endl;
  return 0;
}
