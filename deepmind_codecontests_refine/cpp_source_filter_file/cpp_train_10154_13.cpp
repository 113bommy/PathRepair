#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  char c = getchar();
  long long x = 0;
  bool f = 0;
  for (; !isdigit(c); c = getchar()) f ^= !(c ^ 45);
  for (; isdigit(c); c = getchar()) x = (x << 1) + (x << 3) + (c ^ 48);
  if (f) x = -x;
  return x;
}
struct linearbase {
  long long a[66], cnt;
  void clear() { memset(a, 0, sizeof a); }
  bool ins(long long x) {
    for (register long long i = (63); i >= (0); --i)
      if (x >> i & 1)
        if (!a[i]) {
          a[i] = x, cnt++;
          return 1;
        } else
          x ^= a[i];
    return 0;
  }
} s;
long long n, a, b, sum;
signed main() {
  n = read();
  for (register long long i = (1); i <= (n); ++i)
    a = read(), b = read(), s.ins(a ^ b), sum ^= a;
  if (s.ins(sum))
    cout << 1 << '/' << 1;
  else
    cout << ((1 << s.cnt) - 1) << '/' << (1 << s.cnt);
  return 0;
}
