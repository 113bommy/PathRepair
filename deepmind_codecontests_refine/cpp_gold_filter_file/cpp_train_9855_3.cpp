#include <bits/stdc++.h>
using namespace std;
long long bgm(long long a, long long b, long long m) {
  a %= m;
  long long rem = 1;
  while (b) {
    if (b & 1) rem = (rem * a) % m;
    a = (a * a) % m;
    b >>= 1;
  }
  return rem;
}
long long inv(long long a, long long mod) { return bgm(a, mod - 2, mod); }
long long in() {
  long long a;
  assert(scanf("%lld", &a) != EOF);
  return a;
}
double dl() {
  double a;
  assert(scanf("%lf", &a) != EOF);
  return a;
}
const int MAX = 100005;
const int LEN = 13;
const long long MOD = 1000000007;
double ttm;
int n;
int len;
int length(int x) {
  int ret = 0;
  while (x != 0) x /= 10, ++ret;
  return ret;
}
bool check(int l, int x) {
  long long num = 0;
  for (int i = 1; i + i <= l; i++) num = num * 10 + 7;
  for (int i = 1; i + i <= l; i++) num = num * 10 + 4;
  return num < n;
}
void solve(int a, int b, long long num) {
  if (a == 0 and b == 0) {
    if (num >= n) {
      printf("%lld", (long long)(num)), puts("");
      exit(0);
    }
    return;
  }
  if (a) solve(a - 1, b, num * 10 + 4);
  if (b) solve(a, b - 1, num * 10 + 7);
}
int main() {
  n = in();
  len = length(n);
  if (len & 1) ++len;
  if (check(len, n) == true) len += 2;
  solve(len / 2, len / 2, 0);
  return 0;
}
