#include <bits/stdc++.h>
using namespace std;
inline long long rd() {
  long long x = 0;
  bool neg = false;
  char c = getchar();
  while (c != '-' && (c < '0' || c > '9')) c = getchar();
  if (c == '-') neg = true, c = getchar();
  while (c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
  if (neg) x = -x;
  return x;
}
inline void write(long long x) {
  if (x < 0) {
    putchar('-');
    x = -x;
  }
  if (x > 9) write(x / 10);
  putchar(x % 10 + '0');
}
pair<long long, long long> calc(long long x1, long long y1, long long x2,
                                long long y2) {
  long long len1 = x2 - x1 + 1;
  long long len2 = y2 - y1 + 1;
  long long sum = len1 * len2;
  if (len1 % 2 == 0 || len2 % 2 == 0) return {sum / 2, sum / 2};
  if ((x1 + y1) % 2 == 0)
    return {sum / 2 + 1, sum / 2};
  else
    return {sum / 2, sum / 2 + 1};
}
long long m, n;
pair<long long, long long> res;
void solve() {
  cin >> m >> n;
  long long x1, y1, x2, y2, x3, y3, x4, y4;
  cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
  res = calc(1, 1, m, n);
  pair<long long, long long> z = calc(x1, y1, x2, y2);
  res.first -= z.first;
  res.second -= z.second;
  res.first += (z.first + z.second);
  z = calc(x3, y3, x4, y4);
  res.first -= z.first;
  res.second -= z.second;
  res.second += (z.first + z.second);
  x1 = max(x1, x3);
  y1 = max(y1, y3);
  x2 = min(x2, x4);
  y2 = min(y2, y4);
  if (x1 <= x2 && y1 <= y2) {
    pair<long long, long long> z = calc(x1, y1, x2, y2);
    res.first += z.first;
    res.second += z.second;
    res.first -= (z.first + z.second);
  }
  cout << res.first << ' ' << res.second << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  long long T;
  cin >> T;
  while (T--) solve();
  return 0;
}
