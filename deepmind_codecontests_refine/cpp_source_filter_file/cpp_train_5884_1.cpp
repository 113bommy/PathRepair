#include <bits/stdc++.h>
using namespace std;
long long int min(long long int a, long long int b) { return a < b ? a : b; }
long long int min(long long int a, long long int b, long long int c) {
  a = min(a, b);
  a = min(a, c);
  return a;
}
long long int max(long long int a, long long int b) { return a > b ? a : b; }
long long int max(long long int a, long long int b, long long int c) {
  a = max(a, b);
  a = max(a, c);
  return a;
}
long long int dsum(long long int n) {
  long long int ans = 0;
  while (n) {
    ans += (n % 10);
    n /= 10;
  }
  return ans;
}
long long int power(long long int a, long long int b) {
  long long int res = 1;
  while (b) {
    if (b & 1) res = res * a;
    a = a * a;
    b >>= 1;
  }
  return res;
}
struct pll {
  long long int x, y;
};
bool comp(pll a, pll b) {
  if (a.x == b.x)
    return a.y < b.y;
  else
    return a.x < b.x;
}
long long int decim(string s) {
  long long int ans = 0, a = 1, n = s.length(), b, c;
  for (long long int i = n - 1; i >= 0; i--) {
    b = s[i] - '0';
    c = a * b;
    ans += c;
    a *= 2;
  }
  return ans;
}
void solve(long long int the) {
  char ch;
  double aa, bb, cc, dd, xx;
  string s1, s2, s3, str;
  long long int i, j, k, a, b, c, d, n, m, l, r, x, y, z, low, high, mid,
      sum = 0, ans = 0, temp, t;
  cin >> a >> b;
  c = log2(a);
  c++;
  d = log2(b);
  d++;
  for (i = c; i <= d; i++) {
    s1 = "";
    for (j = 0; j < i; j++) s1.push_back('1');
    for (j = c - 1; j > 0; j--) {
      s1[j] = '0';
      x = decim(s1);
      if (x >= a && x <= b) {
        ans++;
      }
      s1[j] = '1';
    }
  }
  cout << ans;
}
int main() {
  long long int t = 1, c = 1;
  while (t--) {
    solve(c);
    c++;
  }
  return 0;
}
