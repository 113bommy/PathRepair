#include <bits/stdc++.h>
using namespace std;
void FastInputOutput() {
  ios_base ::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
inline int D() {
  int t;
  scanf("%d", &t);
  return t;
}
inline long long LLD() {
  long long t;
  scanf("%lld", &t);
  return t;
}
long long power(long long x, long long p, long long m) {
  long long res = 1;
  while (p) {
    if (p & 1) res = (res * x) % m;
    x = (x * x) % m;
    p >>= 1;
  }
  return res;
}
long double ModLog(long double base, long double x) {
  return (logl(x) / logl(base));
}
const int N = 1e3 + 5, MX = 1e9;
bool a[N][N];
int main() {
  int n = D();
  for (int i = 1; i <= n; ++i) {
    int r = D(), c = D();
    a[r][c] = 1;
  }
  int e = 1000;
  long long ans = 0;
  for (int i = 1; i <= e; ++i) {
    long long cnt = 0;
    int r = 1, c = i;
    while (c <= e && r <= e) {
      cnt += a[r][c];
      ++r, ++c;
    }
    ans += (cnt * (cnt - 1)) / 2;
  }
  for (int i = 1; i <= e; ++i) {
    long long cnt = 0;
    int r = i, c = 1;
    while (c <= e && r <= e) {
      cnt += a[r][c];
      ++r, ++c;
    }
    ans += (cnt * (cnt - 1)) / 2;
  }
  for (int i = 1; i <= e; ++i) {
    long long cnt = 0;
    int r = 1, c = i;
    while (c > 0 && r <= e) {
      cnt += a[r][c];
      ++r, --c;
    }
    ans += (cnt * (cnt - 1)) / 2;
  }
  for (int i = 1; i <= e; ++i) {
    long long cnt = 0;
    int r = i, c = e;
    while (c > 0 && r <= e) {
      cnt += a[r][c];
      ++r, --c;
    }
    ans += (cnt * (cnt - 1)) / 2;
  }
  printf("%lld", ans / 2);
  return 0;
}
