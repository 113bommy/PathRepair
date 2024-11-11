#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int nm = 0;
  bool fh = true;
  char cw = getchar();
  for (; !isdigit(cw); cw = getchar()) fh ^= (cw == '-');
  for (; isdigit(cw); cw = getchar()) nm = nm * 10 + (cw - '0');
  return fh ? nm : -nm;
}
namespace CALC {
inline long long add(long long x, long long y) {
  return (x + y >= 1000000007) ? (x + y - 1000000007) : (x + y);
}
inline long long mns(long long x, long long y) {
  return (x - y < 0) ? (x - y + 1000000007) : (x - y);
}
inline long long mul(long long x, long long y) { return x * y % 1000000007; }
inline void upd(long long &x, long long y) {
  x = ((x + y >= 1000000007) ? (x + y - 1000000007) : (x + y));
}
inline void dec(long long &x, long long y) {
  x = ((x - y < 0) ? (x - y + 1000000007) : (x - y + 1000000007));
}
inline long long qpow(long long x, long long sq) {
  long long res = 1;
  for (; sq; sq >>= 1, x = mul(x, x))
    if (sq & 1) res = mul(res, x);
  return res;
}
}  // namespace CALC
using namespace CALC;
bitset<2019> F[1 << 16 | 100];
int p[2020], n, k, u[2020], v[2020], m, b[2020], S[2020], top;
inline void solve(int x) {
  top = 0;
  for (int i = 0; i < n; i++)
    if (b[i] == x) S[++top] = i;
  while (top > 1) {
    int t1 = S[top], t2 = S[top - 1];
    printf("%d %d\n", p[t1], p[t2]);
    top -= 2, p[t1] += p[t2], b[t2] = -1;
    while (p[t1] % k == 0) p[t1] /= k, b[t1]--;
    if (b[t1] == x) {
      S[++top] = t1;
      continue;
    }
  }
}
int main() {
  n = read(), k = read();
  for (int i = 0; i < n; i++) p[i] = read();
  F[0][0] = 1;
  for (int sta = 0; sta < (1 << n); sta++) {
    for (int j = 2000 / k; j > 0; --j) F[sta][j] = (F[sta][j * k] | F[sta][j]);
    for (int j = 0; j < n; j++)
      if (!((sta >> j) & 1)) F[sta | (1 << j)] |= (F[sta] << p[j]);
  }
  int sta = (1 << n) - 1;
  if (!F[sta][1]) {
    puts("NO");
    return 0;
  }
  puts("YES");
  for (int tms = 0, lev = 0, sm = 1; tms < n; ++tms) {
    int pos = -1;
    for (int i = 0; i < n; i++)
      if (sm >= p[i] && ((sta >> i) & 1))
        if (F[sta ^ (1 << i)][sm - p[i]]) {
          pos = i;
          break;
        }
    if (pos >= 0) {
      b[pos] = lev, sm -= p[pos], sta ^= (1 << pos);
      continue;
    }
    --tms, sm *= k, ++lev;
  }
  for (int i = 30; i > 0; --i) solve(i);
  return 0;
}
