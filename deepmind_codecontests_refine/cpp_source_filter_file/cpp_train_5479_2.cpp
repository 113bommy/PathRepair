#include <bits/stdc++.h>
using namespace std;
inline long long rd() {
  long long x = 0, f = 1;
  char c = getchar();
  for (; !isdigit(c); c = getchar())
    if (c == '-') f = -1;
  for (; isdigit(c); c = getchar()) x = (x << 1) + (x << 3) + (c ^ 48);
  return x * f;
}
void write(long long x) {
  if (x < 0) x = -x, putchar('-');
  if (x >= 10) write(x / 10);
  putchar(x % 10 + '0');
}
void writeln(long long x) {
  write(x);
  puts("");
}
int n, m;
map<long long, long long> mp;
int main() {
  n = rd(), m = rd();
  mp[m - 1] = 0;
  for (register int i = (1); i < int(n); ++i) {
    m = rd();
    while (true) {
      auto it = mp.lower_bound(m);
      if (it != mp.end()) {
        mp[it->first % m] =
            max(mp[it->first % m], it->second + it->first / m * m * i);
        mp[m - 1] =
            max(mp[m - 1], it->second + (it->first - m + 1) / m * m * i);
        mp.erase(it++);
      } else
        break;
    }
  }
  long long ans = 0;
  for (auto w : mp) ans = max(ans, w.first * n + w.second);
  writeln(ans);
  return 0;
}
