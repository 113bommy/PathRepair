#include <bits/stdc++.h>
using namespace std;
long long n, a[40], dp[20][20];
string s;
vector<char> vec;
long long power(long long x, long long k) {
  long long res = 1;
  for (int i = 0; i < k; i++) {
    long long last = res;
    res *= x;
    if (res / x != last) return -1;
  }
  return res;
}
long long fun(long long x, long long y) {
  if (dp[x][y] != -1) return dp[x][y];
  if (x == n && y == n) return 0;
  dp[x][y] = 0;
  if (x < n) {
    dp[x][y] = power(10, n - x - 1) * a[x + y] + fun(x + 1, y);
  }
  if (y < n) {
    dp[x][y] = max(dp[x][y], power(10, n - y - 1) * a[x + y] + fun(x, y + 1));
  }
  return dp[x][y];
}
void print(long long x, long long y) {
  if (x == n && y == n) return;
  if (x < n) {
    if (dp[x][y] == power(10, n - x - 1) * a[x + y] + fun(x + 1, y)) {
      vec.push_back('H');
      print(x + 1, y);
      return;
    }
  }
  if (y < n) {
    if (dp[x][y] == power(10, n - y - 1) * a[x + y] + fun(x, y + 1)) {
      vec.push_back('M');
      print(x, y + 1);
      return;
    }
  }
}
int main() {
  memset(dp, -1, sizeof(dp));
  cin >> n >> s;
  for (int i = 0; i < s.length(); i++) {
    a[i] = s[i] - '0';
  }
  fun(0, 0);
  print(0, 0);
  for (int i = 0; i < vec.size(); i++) cout << vec[i];
  return 0;
}
