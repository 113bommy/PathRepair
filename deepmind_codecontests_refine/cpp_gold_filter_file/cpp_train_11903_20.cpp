#include <bits/stdc++.h>
using namespace std;
int row[] = {0, 1, 0, -1};
int col[] = {1, 0, -1, 0};
const long long N = 1e6 + 10;
const long long M = 1e18 + 7;
const long long H = 1e9 + 7;
const long long base = 131;
long long logx(long long a, long long bs) { return log(a) / log(bs); }
long long Max(long long a, long long b) {
  if (a > b) return a;
  return b;
}
long long Min(long long a, long long b) {
  if (a > b) return b;
  return a;
}
long long big_mul(long long a, long long b, long long m) {
  long long x = 0, y = a % m;
  while (b > 0) {
    if (b & 1) x = (x + y) % m;
    y = (2 * y) % m;
    b >>= 1;
  }
  return x % m;
}
long long big_mod(long long a, long long b, long long m) {
  long long x = 1, y = a % m;
  while (b > 0) {
    if (b & 1) x = (x * y) % m;
    y = (y * y) % m;
    b >>= 1;
  }
  return x % m;
}
long long Big_mod(long long a, long long b, long long m) {
  long long x = 1, y = a % m;
  while (b > 0) {
    if (b & 1) x = big_mul(x, y, m);
    y = big_mul(y, y, m);
    b >>= 1;
  }
  return x % m;
}
long long mod_inverse(long long a, long long m) { return big_mod(a, m - 2, m); }
long long GCD(long long a, long long b) {
  if (!a) return b;
  return GCD(b % a, a);
}
vector<int> pre(N);
int bs1(int l, int r, int k) {
  int value = pre[l - 1];
  while (r - l > 3) {
    int mid = (l + r) / 2;
    if (pre[mid] - value >= k)
      r = mid;
    else
      l = mid;
  }
  for (int i = l; i < r + 1; i++) {
    if (pre[i] - value == k) return i;
  }
  return -1;
}
int bs2(int l, int r, int k) {
  int value = pre[l - 1];
  while (r - l > 3) {
    int mid = (l + r) / 2;
    if (pre[mid] - value <= k)
      l = mid;
    else
      r = mid;
  }
  for (int i = r; i >= l; i--) {
    if (pre[i] - value == k) return i;
  }
  return -1;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  int x;
  cin >> x;
  string str;
  cin >> str;
  for (int i = 0; i < str.size(); i++) {
    if (str[i] == '1')
      pre[i + 1] = pre[i] + 1;
    else
      pre[i + 1] = pre[i];
  }
  long long ans = 0;
  for (int i = 1; i < str.size() + 1; i++) {
    int p = bs1(i, str.size(), x);
    int q = bs2(i, str.size(), x);
    if (p > 0 && q > 0) ans += q - p + 1;
  }
  cout << ans << endl;
  return 0;
}
