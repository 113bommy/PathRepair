#include <bits/stdc++.h>
using namespace std;
inline int read() {
  char c = getchar();
  int x = 0;
  bool f = 0;
  for (; !isdigit(c); c = getchar()) f ^= !(c ^ 45);
  for (; isdigit(c); c = getchar()) x = (x << 1) + (x << 3) + (c ^ 48);
  if (f) x = -x;
  return x;
}
mt19937 rnd(19491001);
int n, a[500005], lst[500005], p, cnt[500005], qwq[500005];
unsigned long long val[500005], h[500005], now;
map<unsigned long long, int> mp;
int main() {
  n = read();
  for (register int i = (1); i <= (n); ++i)
    a[i] = read(), val[i] = rnd() * (1ull << 32) + rnd();
  for (register int i = (1); i <= (n); ++i) lst[i] = qwq[a[i]], qwq[a[i]] = i;
  for (register int i = (1); i <= (n); ++i) {
    cnt[a[i]]++, cnt[a[i]] %= 3;
    if (cnt[a[i]])
      h[i] = h[i - 1] + val[a[i]];
    else
      h[i] = h[i - 1] - val[a[i]] * 2;
  }
  mp[0] = 1;
  long long res = 0;
  p = -1;
  for (register int i = (1); i <= (n); ++i) {
    while (p < lst[lst[lst[i]]] - 1) p++, mp[h[p]]--;
    res += mp[h[i]];
    mp[h[i]]++;
  }
  cout << res;
  return 0;
}
