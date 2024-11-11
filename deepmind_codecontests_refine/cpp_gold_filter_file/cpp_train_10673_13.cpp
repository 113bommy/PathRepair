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
inline void run() {
  int arr[5000];
  int cnt[5000];
  int ans[5000] = {};
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n;) scanf("%d", arr + i++);
  for (int i = 0; i < n;) --arr[i++];
  for (int i = 0; i < n; ++i) {
    int mx = 0, ind = ~0;
    memset(cnt, 0, sizeof cnt);
    for (int j = i; j < n; ++j) {
      if (++cnt[arr[j]] > mx)
        mx = cnt[arr[j]], ind = arr[j];
      else if (cnt[arr[j]] == mx && arr[j] < ind)
        ind = arr[j];
      ++ans[ind];
    }
  }
  for (int i = 0; i < n; ++i) {
    if (i) putchar(' ');
    printf("%d", ans[i]);
  }
  puts("");
}
int main() {
  run();
  return 0;
}
