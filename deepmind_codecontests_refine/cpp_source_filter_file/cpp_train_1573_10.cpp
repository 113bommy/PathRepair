#include <bits/stdc++.h>
using namespace std;
long long int ll_max(long long int a, long long int b, long long int c) {
  return max(a, max(b, c));
}
int int_max(int a, int b, int c) { return max(a, max(b, c)); }
long long int ll_min(long long int a, long long int b, long long int c) {
  return min(a, min(b, c));
}
int int_min(int a, int b, int c) { return min(a, min(b, c)); }
long long int max(int a, long long int b) { return max((long long int)a, b); }
long long int min(int a, long long int b) { return min((long long int)a, b); }
long long int min(long long int a, int b) { return min(a, (long long int)b); }
long long int max(long long int a, int b) { return max(a, (long long int)b); }
long long int dx[] = {0, 0, 1, -1};
long long int dy[] = {1, -1, 0, 0};
long long int power(long long int x, long long int y, long long int m) {
  if (y == 0) return 1;
  long long int a = power(x, y / 2, m);
  if (y % 2) {
    return (a * ((a * x) % m)) % m;
  } else {
    return (a * a) % m;
  }
}
long long int mod_inverse(long long int x, long long int m) {
  return power(x, m - 2, m);
}
long long int fact(long long int n, long long int m) {
  if (n <= 1) return 1;
  return (fact(n - 1, m) * n) % m;
}
long long int ncr(long long int n, long long int r, long long int m) {
  if (r > n) return 0;
  long long int n1 = 1, d1 = 1, d2 = 1;
  n1 = fact(n, m);
  d1 = fact(r, m);
  d2 = fact(n - r, m);
  long long int ans = mod_inverse((d1 * d2) % m, m);
  ans = (ans * n1) % m;
  return ans;
}
int gcd(int a, int b) {
  if (a < b) return gcd(b, a);
  if (a % b == 0) return b;
  return gcd(b, a % b);
}
int ispal(string str) {
  long long int n = str.length(), left = 0, right = n - 1, f = 0;
  while (left <= right) {
    if (str[left++] != str[right--]) {
      f = 1;
      break;
    }
  }
  long long int ans = 0;
  if (f == 0) ans = 1;
  return ans;
}
int main() {
  long long int n;
  cin >> n;
  long long int c = 2, m = 4;
  if (n == 1)
    cout << n;
  else {
    while (m < n) {
      c++;
      m = m * 2;
    }
    cout << c;
  }
  return 0;
}
