#include <bits/stdc++.h>
using namespace std;
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
const double EPS = (1e-7);
const long long mod = (1e9 + 9), OO = 2e18, N = 2020;
long long gcd(long long a, long long b) { return !b ? abs(a) : gcd(b, a % b); }
long long lcm(long long a, long long b) { return abs(a / gcd(a, b)) * b; }
long long Ceil(long long x, long long y) { return (x + y - 1) / y; }
void run(string s) {}
void fast() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}
long long n, m, t = 1, kk, ggg, kkk;
int dp[1001][1001];
string s, s1;
int solve(int x, int y) {
  if (x == n && y == m) return 0;
  if (x == n) return m - y;
  if (y == m) return n - x;
  int& ret = dp[x][y];
  if (~ret) return ret;
  ret = 1e7;
  if (s[x] == s1[y]) ret = min(solve(x + 1, y + 1), ret);
  ret = min(solve(x + 1, y) + 1, ret);
  ret = min(solve(x, y + 1) + 1, ret);
  ret = min(solve(x + 1, y + 1) + 1, ret);
  return ret;
}
int pr = 1;
void build(int x, int y) {
  if (x == n) {
    for (int i = y; i < m; i++) {
      cout << "INSERT " << pr++ << " " << s1[i] << '\n';
    }
    return;
  }
  if (y == m) {
    for (int i = x; i < n; i++) {
      cout << "DELETE " << pr << '\n';
    }
    return;
  }
  if (s[x] == s1[y]) {
    pr++;
    build(x + 1, y + 1);
    return;
  }
  long long op = solve(x, y);
  if (op == solve(x + 1, y + 1) + 1) {
    cout << "REPLACE " << pr++ << " " << s1[y] << '\n';
    build(x + 1, y + 1);
    return;
  }
  if (op == solve(x + 1, y) + 1) {
    cout << "DELETE " << pr << '\n';
    build(x + 1, y);
    return;
  }
  if (op == solve(x, y + 1) + 1) {
    cout << "INSERT " << pr++ << " " << s1[y] << '\n';
    build(x, y + 1);
    return;
  }
}
int main() {
  run("still");
  fast();
  memset(dp, -1, sizeof dp);
  cin >> s >> s1;
  n = s.size(), m = s1.size();
  cout << solve(0, 0) << '\n';
  build(0, 0);
}
