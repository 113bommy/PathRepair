#include <bits/stdc++.h>
using namespace std;
template <class T>
inline void remax(T& A, T B) {
  if (A < B) A = B;
}
template <class T>
inline void remin(T& A, T B) {
  if (A > B) A = B;
}
string ToString(long long num) {
  string ret;
  bool neg = false;
  if (num < 0) num *= ~0, neg = true;
  do {
    ret += ((num % 10) + '0');
    num /= 10;
  } while (num);
  if (neg) ret += '-';
  reverse(ret.begin(), ret.end());
  return ret;
}
long long ToNumber(string s) {
  long long r = 0, p = 1;
  int e = (s[0] == '-');
  for (int i = (int)s.size() - 1; i >= e; --i) r += (s[i] - '0') * p, p *= 10;
  if (e) r *= ~0;
  return r;
}
long long Gcd(long long a, long long b) {
  while (a %= b ^= a ^= b ^= a)
    ;
  return b;
}
long long Power(long long base, unsigned long long power) {
  long long ret = 1;
  while (power) {
    if (power & 1) ret *= base;
    power >>= 1;
    base *= base;
  }
  return ret;
}
long long PowerMod(long long base, unsigned long long power, long long mod) {
  if (!power) return 1 % mod;
  if (power & 1) return (base * PowerMod(base, power - 1, mod)) % mod;
  return PowerMod((base * base) % mod, power >> 1, mod);
}
int Log(long long num, long long base) {
  int ret = 0;
  while (num) {
    ++ret;
    num /= base;
  }
  return ret;
}
int arr[100][100];
int t[10000][4];
inline void run() {
  int n, m, q;
  scanf("%d%d%d", &n, &m, &q);
  for (int i = 0; i < q; ++i) {
    for (int j = 0; j < 2; ++j) scanf("%d", &t[i][j]);
    if (t[i][0] == 3) scanf("%d%d", &t[i][2], &t[i][3]);
  }
  for (int i = q - 1; ~i; --i)
    if (t[i][0] == 1) {
      int x = arr[--t[i][1]][m - 1];
      for (int j = m - 1; j; --j) arr[t[i][1]][j] = arr[t[i][1]][j - 1];
      arr[t[i][1]][0] = x;
    } else if (t[i][0] == 2) {
      int x = arr[n - 1][--t[i][1]];
      for (int j = n - 1; j; --j) arr[j][t[i][1]] = arr[j - 1][t[i][1]];
      arr[0][t[i][1]] = x;
    } else
      arr[--t[i][1]][--t[i][2]] = t[i][3];
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (j) putchar(' ');
      printf("%d", arr[i][j]);
    }
    puts("");
  }
  memset(arr, 0, sizeof arr);
}
int main() {
  run();
  return 0;
}
