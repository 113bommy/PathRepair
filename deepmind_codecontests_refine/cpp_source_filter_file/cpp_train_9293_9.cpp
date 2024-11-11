#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  long long x = 0, f = 1;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    x = (x << 3) + (x << 1) + (c ^ 48);
    c = getchar();
  }
  return f == 1 ? x : -x;
}
inline void print(long long x) {
  if (x < 0) x = ~x + 1, putchar('-');
  if (x >= 10) print(x / 10);
  putchar((x % 10) | 48);
}
long long n, m;
long long L, R;
long long head[500010], nxt[10000010], to[10000010];
long long tot;
set<long long> st;
long long cnt[500010];
void add(long long x, long long y) {
  nxt[++tot] = head[x], head[x] = tot, to[tot] = y;
}
signed main() {
  n = read(), m = read(), L = read(), R = read();
  for (long long i = 1; i <= 200000; ++i)
    for (long long j = i; j <= 200000; j += i) add(j, i);
  long long lstL = m + 1, lstR = m;
  for (long long i = 1; i <= n; ++i) {
    long long l = ceil((double)L / i), r = floor((double)R / i);
    while (lstL > l) {
      --lstL;
      for (long long j = head[lstL]; j; j = nxt[j]) {
        long long v = to[j];
        if (cnt[v] == 0) st.insert(v);
        ++cnt[v];
      }
    }
    while (lstR > r) {
      for (long long j = head[lstR]; j; j = nxt[j]) {
        long long v = to[j];
        --cnt[v];
        if (cnt[v] == 0) st.erase(v);
      }
      --lstR;
    }
    bool flag = 0;
    for (long long j = head[i]; j; j = nxt[j]) {
      long long d = to[j];
      long long t = i / d;
      auto it = st.upper_bound(t);
      if (it != st.end() && (d * (*it) <= n)) {
        flag = 1;
        long long k = lstR / (*it);
        printf("%d %d %d %d\n", i, k * (*it), d * (*it), k * t);
        break;
      }
    }
    if (!flag) printf("-1\n");
  }
}
