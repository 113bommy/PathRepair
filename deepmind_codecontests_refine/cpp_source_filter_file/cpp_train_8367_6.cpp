#include <bits/stdc++.h>
using namespace std;
template <typename T>
void chkmax(T &x, T y) {
  x = x > y ? x : y;
}
template <typename T>
void chkmin(T &x, T y) {
  x = x > y ? y : x;
}
const int INF = 2139062143;
template <typename T>
void read(T &x) {
  x = 0;
  bool f = 1;
  char ch;
  do {
    ch = getchar();
    if (ch == '-') f = 0;
  } while (ch > '9' || ch < '0');
  do {
    x = x * 10 + ch - '0';
    ch = getchar();
  } while (ch >= '0' && ch <= '9');
  x = f ? x : -x;
}
template <typename T>
void write(T x) {
  if (x < 0) x = ~x + 1, putchar('-');
  if (x > 9) write(x / 10);
  putchar(x % 10 + '0');
}
const int N = 1e5 + 7;
struct Node {
  long long x, y, id;
} s[N];
bool cmp1(Node a, Node b) { return a.x < b.x; }
bool cmp2(Node a, Node b) { return a.y < b.y; }
long long n, l[N], r[N];
struct BIT {
  long long c[N];
  inline long long lowbit(long long x) { return x & -x; }
  inline void add(long long i, long long x) {
    for (; i <= 2 * n; i += lowbit(i)) c[i] += x;
  }
  inline long long ask(long long i) {
    long long sum = 0;
    for (; i; i -= lowbit(i)) sum += c[i];
    return sum;
  }
} bit;
signed main() {
  read(n);
  for (long long i = 1; i <= n; i++) {
    read(s[i].x);
    read(s[i].y);
    if (s[i].x > s[i].y) swap(s[i].x, s[i].y);
    s[i].id = i;
  }
  sort(s + 1, s + n + 1, cmp1);
  memset(bit.c, 0, sizeof(bit.c));
  for (long long i = 1; i <= n; i++) {
    l[s[i].id] += bit.ask(s[i].x) + bit.ask(2 * n) - bit.ask(s[i].y);
    bit.add(s[i].y, 1);
  }
  sort(s + 1, s + n + 1, cmp2);
  memset(bit.c, 0, sizeof(bit.c));
  for (long long i = 1; i <= n; i++) {
    r[s[i].id] += bit.ask(2 * n) - bit.ask(s[i].x);
    bit.add(s[i].x, 1);
  }
  memset(bit.c, 0, sizeof(bit.c));
  for (long long i = n; i >= 1; i--) {
    l[s[i].id] += bit.ask(2 * n) - bit.ask(s[i].y);
    bit.add(s[i].x, 1);
  }
  long long ans = 1ll * n * (n - 1) / 2 * (n - 2) / 3, ret = 0;
  assert(ans >= 0);
  for (long long i = 1; i <= n; i++) {
    ans -= (1ll * l[i] * r[i]);
    ret += 1ll * (l[i] + r[i]) * (n - l[i] - r[i] - 1);
  }
  printf("%lld\n", ans - ret / 2);
  return 0;
}
