#include <bits/stdc++.h>
using namespace std;
long long gcd(long long x, long long y) {
  if (y == 0) return x;
  return gcd(y, x % y);
}
long long lcm(long long a, long long b) { return a / gcd(a, b) * b; }
void XsliferX() {
  ios::sync_with_stdio(0);
  ios_base::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
}
long long f_p(long long x, int y) {
  if (y == 0)
    return 1;
  else if (y % 2 == 0)
    return f_p(x * x, y / 2);
  else
    return x * f_p(x * x, y / 2);
}
long long l_p(long long n) {
  n = n | (n >> 1);
  n = n | (n >> 2);
  n = n | (n >> 4);
  n = n | (n >> 8);
  return (n + 1) >> 1;
}
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int main() {
  XsliferX();
  long long n, ix = -1, jx = -1, sum = 0, s = 0, s1 = 0;
  cin >> n;
  if (n == 1) {
    cout << 1;
    return 0;
  }
  long long arr[n][n];
  for (int i = 0; i < n; i++) {
    sum = 0;
    for (int j = 0; j < n; j++) {
      cin >> arr[i][j];
      if (arr[i][j] == 0) {
        ix = i;
        jx = j;
      }
      sum += arr[i][j];
    }
    if (i != ix)
      s = sum;
    else
      s1 = sum;
  }
  long long d = s - s1;
  arr[ix][jx] = d;
  for (int i = 0; i < n; i++) {
    sum = 0;
    for (int j = 0; j < n; j++) {
      sum += arr[i][j];
    }
    if (sum != s) {
      cout << -1;
      return 0;
    }
  }
  for (int i = 0; i < n; i++) {
    sum = 0;
    for (int j = 0; j < n; j++) {
      sum += arr[j][i];
    }
    if (sum != s) {
      cout << -1;
      return 0;
    }
  }
  sum = 0;
  for (int i = 0; i < n; i++) {
    sum += arr[i][i];
  }
  if (sum != s) {
    cout << -1;
    return 0;
  }
  sum = 0;
  for (int i = 0; i < n; i++) {
    sum += arr[i][n - i - 1];
  }
  if (sum != s) {
    cout << -1;
    return 0;
  }
  if (d != 0)
    cout << d;
  else
    cout << -1;
  return 0;
}
