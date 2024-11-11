#include <bits/stdc++.h>
using namespace std;
template <typename T>
void read(T &x) {
  x = 0;
  char c = getchar();
  int f = 0;
  for (; !isdigit(c); c = getchar()) f |= c == '-';
  for (; isdigit(c); c = getchar()) x = x * 10 + (c ^ '0');
  if (f) x = -x;
}
template <typename T>
void write(T x, char ed = '\n') {
  static short st[30], tp;
  if (x < 0) putchar('-'), x = -x;
  do st[++tp] = x % 10, x /= 10;
  while (x);
  while (tp) putchar(st[tp--] | '0');
  putchar(ed);
}
unordered_map<long long, pair<long long, long long>> f[20];
pair<long long, long long> solve(int ht, long long n) {
  if (!n) return make_pair(0, 0);
  if (n < 10) return make_pair(1, min(0ll, n - ht));
  if (f[ht].count(n)) return f[ht][n];
  long long hbt = 1, ans = 0, tn = n;
  while (n / 10 >= hbt) hbt *= 10;
  while (n > 0) {
    int k = n / hbt;
    pair<long long, long long> tmp = solve(max(ht, k), n - k * hbt);
    n = k * hbt + tmp.second, ans += tmp.first;
    if (!n) break;
    if (n % hbt == 0) ++ans, n -= max(ht, k);
  }
  return f[ht][tn] = make_pair(ans, n);
}
long long n;
int main() {
  read(n), write(solve(0, n).first);
  return 0;
}
