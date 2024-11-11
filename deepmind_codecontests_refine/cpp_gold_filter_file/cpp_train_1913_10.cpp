#include <bits/stdc++.h>
using namespace std;
int getint() {
  int ret = 0, mul = 1;
  char ch = getchar();
  while ((ch < '0' || ch > '9') && ch != '-') ch = getchar();
  if (ch == '-') {
    mul = -1;
    ch = getchar();
  }
  do ret = (ret << 1) + (ret << 3) + ch - '0';
  while ((ch = getchar()) && ('0' <= ch && ch <= '9'));
  return ret * mul;
}
void getint(int &x) { x = getint(); }
long long getLL() {
  long long ret = 0, mul = 1LL;
  char ch = getchar();
  while ((ch < '0' || ch > '9') && ch != '-') ch = getchar();
  if (ch == '-') {
    mul = -1LL;
    ch = getchar();
  }
  do ret = (ret << 1) + (ret << 3) + ch - '0';
  while ((ch = getchar()) && ('0' <= ch && ch <= '9'));
  return ret * mul;
}
void getLL(long long &x) { x = getLL(); }
const long long MAXN = 1000000009;
long long n, x, y, c, l, r, mid;
long long kombi(long long s) { return (s * s + s) / 2LL; }
long long hitung(long long s, long long x, long long y) {
  if (x >= s && y >= s) return kombi(s);
  if (x + y <= s + 1) return x * y;
  if (x >= s) return kombi(s) - kombi(s - y);
  if (y >= s) return kombi(s) - kombi(s - x);
  return x * y - kombi(x + y - s - 1);
}
long long nyala(long long s) {
  long long ret = 1;
  ret += hitung(s - 1, x - 1, y - 1);
  ret += hitung(s - 1, n - x, y - 1);
  ret += hitung(s - 1, n - x, n - y);
  ret += hitung(s - 1, x - 1, n - y);
  ret += min(s, x - 1) + min(s, y - 1) + min(s, n - x) + min(s, n - y);
  return ret;
}
int main() {
  scanf("%I64d%I64d%I64d%I64d", &n, &x, &y, &c);
  l = 0;
  r = MAXN;
  for (long long coba = 0; coba < 100; ++coba) {
    mid = (l + r) / 2LL;
    if (nyala(mid) >= c)
      r = mid;
    else
      l = mid + 1;
  }
  printf("%I64d\n", mid);
  return 0;
}
