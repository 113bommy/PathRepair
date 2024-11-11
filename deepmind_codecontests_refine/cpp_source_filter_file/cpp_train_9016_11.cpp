#include <bits/stdc++.h>
using namespace std;
namespace io {
const int L = (1 << 19) + 1;
char ibuf[L], *iS, *iT, c;
int f;
char gc() {
  if (iS == iT) {
    iT = (iS = ibuf) + fread(ibuf, 1, L, stdin);
    return iS == iT ? EOF : *iS++;
  }
  return *iS++;
}
template <class I>
void gi(I& x) {
  for (f = 1, c = gc(); c < '0' || c > '9'; c = gc())
    if (c == '-') f = -1;
  for (x = 0; c <= '9' && c >= '0'; c = gc()) x = x * 10 + (c & 15);
  x *= f;
}
};  // namespace io
using io::gc;
using io::gi;
vector<int> f[100010];
int n, a, m, k;
int main() {
  gi(n);
  gi(k);
  gi(m);
  for (register int i = 1; i <= n; i++) gi(a), f[a % m].push_back(a);
  for (register int i = 0; i <= m - 1; i++)
    if (f[i].size() >= k) {
      puts("YES");
      for (register int j = 0; j <= k - 1; j++) printf("%d ", f[i][j]);
      return 0;
    }
  puts("NO");
  return 0;
}
