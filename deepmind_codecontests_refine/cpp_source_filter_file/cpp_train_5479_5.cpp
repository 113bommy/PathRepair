#include <bits/stdc++.h>
using namespace std;
namespace io {
const int SIZE = (1 << 21) + 1;
char ibuf[SIZE], *iS, *iT, c;
int f;
template <class I>
inline void gi(I &x) {
  for (f = 1, c = (iS == iT ? (iT = (iS = ibuf) + fread(ibuf, 1, SIZE, stdin),
                              (iS == iT ? EOF : *iS++))
                            : *iS++);
       c < '0' || c > '9';
       c = (iS == iT ? (iT = (iS = ibuf) + fread(ibuf, 1, SIZE, stdin),
                       (iS == iT ? EOF : *iS++))
                     : *iS++))
    if (c == '-') f = -1;
  for (x = 0; c <= '9' && c >= '0';
       c = (iS == iT ? (iT = (iS = ibuf) + fread(ibuf, 1, SIZE, stdin),
                       (iS == iT ? EOF : *iS++))
                     : *iS++))
    x = (x << 1) + (x << 3) + (c & 15);
  x *= f;
}
}  // namespace io
using io ::gi;
map<long long, long long> f;
map<long long, long long>::iterator it, pos;
vector<pair<long long, long long>> add;
int main() {
  register int n, i;
  register long long m, j, ans;
  register pair<long long, long long> x;
  gi(n);
  gi(m);
  f[m - 1] = 0;
  for (i = 1; i < n; ++i) {
    gi(m);
    pos = f.lower_bound(m);
    add.clear();
    for (it = pos; it != f.end(); ++it) {
      j = it->first;
      add.push_back(make_pair(j % m, it->second + i * (j - j % m)));
      add.push_back(make_pair(m - 1, it->second + (j + 1) / m * m - m));
    }
    f.erase(pos, f.end());
    for (auto x : add) f[x.first] = max(f[x.first], x.second);
  }
  ans = 0;
  for (it = f.begin(); it != f.end(); ++it)
    ans = max(ans, it->first * n + it->second);
  printf("%lld\n", ans);
  return 0;
}
