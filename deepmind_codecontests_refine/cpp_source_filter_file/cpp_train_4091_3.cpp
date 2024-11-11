#include <bits/stdc++.h>
inline long long Max(long long x, long long y) { return x > y ? x : y; }
inline long long Min(long long x, long long y) { return x < y ? x : y; }
inline long long Abs(long long x) { return x < 0 ? ~x + 1 : x; }
inline long long read() {
  long long r = 0;
  bool w = 0;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') w = 1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    r = (r << 3) + (r << 1) + (ch ^ 48);
    ch = getchar();
  }
  return w ? ~r + 1 : r;
}
const long long N = 2e5 + 10;
struct Node {
  long long pos;
  long long dis;
} a[N];
bool cmp(Node x, Node y) { return x.dis > y.dis; }
bool vis[N];
signed main() {
  long long T = read();
  while (T--) {
    long long n = read();
    long long W = read(), sum = 0;
    long long cnt = 0;
    bool f = 0;
    for (long long i = 1; i <= n; ++i)
      a[i].dis = read(), a[i].pos = i, vis[i] = 0;
    std::sort(a + 1, a + n + 1, cmp);
    for (long long i = n; i >= 1; --i) {
      if (sum + a[i].dis <= W) sum += a[i].dis, vis[a[i].pos] = 1, ++cnt;
      if (sum * 2 >= W) {
        f = 1;
        break;
      }
    }
    if (!f) {
      puts("-1");
      continue;
    }
    printf("%lld\n", cnt);
    for (long long i = 1; i <= n; ++i)
      if (vis[i]) printf("%lld ", i);
    puts("");
  }
  return 0;
}
