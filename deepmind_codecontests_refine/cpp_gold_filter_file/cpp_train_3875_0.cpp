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
const long long maxn = 100050;
long long n, val[maxn], s[maxn];
struct Segment {
  long long pos, id;
  char c;
  bool operator<(const Segment &b) const {
    if (pos != b.pos) return pos < b.pos;
    return c == 'l';
  }
} a[maxn << 1], b[maxn << 1];
inline long long random(long long a, long long b) {
  long long res = 0;
  for (register long long i = (0); i <= (5); ++i)
    res = res * 1000 + rand() % 1000;
  return res % (b - a + 1) + a;
}
signed main() {
  srand(time(NULL));
  n = read();
  for (register long long i = (1); i <= (n); ++i) {
    a[i * 2 - 1].pos = read();
    a[i * 2].pos = read();
    b[i * 2 - 1].pos = read();
    b[i * 2].pos = read();
    a[i * 2 - 1].id = a[i * 2].id = b[i * 2 - 1].id = b[i * 2].id = i;
    a[i * 2 - 1].c = b[i * 2 - 1].c = 'l';
    a[i * 2].c = b[i * 2].c = 'r';
    val[i] = random(1, 1e18);
  }
  sort(a + 1, a + n * 2 + 1);
  sort(b + 1, b + n * 2 + 1);
  long long Xor = 0;
  for (register long long i = (1); i <= (n * 2); ++i) {
    if (a[i].c == 'r')
      Xor ^= val[a[i].id];
    else
      s[a[i].id] ^= Xor;
  }
  Xor = 0;
  for (register long long i = (n * 2); i >= (1); --i) {
    if (a[i].c == 'l')
      Xor ^= val[a[i].id];
    else
      s[a[i].id] ^= Xor;
  }
  Xor = 0;
  for (register long long i = (1); i <= (n * 2); ++i) {
    if (b[i].c == 'r')
      Xor ^= val[b[i].id];
    else
      s[b[i].id] ^= Xor;
  }
  Xor = 0;
  for (register long long i = (n * 2); i >= (1); --i) {
    if (b[i].c == 'l')
      Xor ^= val[b[i].id];
    else
      s[b[i].id] ^= Xor;
  }
  for (register long long i = (1); i <= (n); ++i)
    if (s[i] > 0) {
      puts("No");
      return 0;
    }
  puts("Yes");
  return 0;
}
