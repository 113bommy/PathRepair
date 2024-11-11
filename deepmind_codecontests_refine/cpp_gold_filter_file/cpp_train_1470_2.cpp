#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int sum = 0, p = 1;
  char ch = getchar();
  while (!(('0' <= ch && ch <= '9') || ch == '-')) ch = getchar();
  if (ch == '-') p = -1, ch = getchar();
  while ('0' <= ch && ch <= '9') sum = sum * 10 + ch - 48, ch = getchar();
  return sum * p;
}
const int maxp = 2e6 + 20;
const int maxn = maxp;
const int mod = 1e9 + 7;
int n, p[maxn], mark[maxn], prime[maxn], tot, d[maxn];
inline void prepare() {
  for (int i = (2), _end_ = (2e6); i <= _end_; i++) {
    if (!mark[i]) prime[++tot] = i, mark[i] = tot, d[i] = i;
    for (int j = 1; i * prime[j] <= 2e6; j++) {
      int k = i * prime[j];
      mark[k] = 1;
      d[k] = prime[j];
      if (!(i % prime[j])) break;
    }
  }
}
inline void init() {
  n = read();
  for (int i = (1), _end_ = (n); i <= _end_; i++) p[i] = read();
  sort(p + 1, p + n + 1);
}
int cnt[maxp], ok[maxp];
int tag[maxp];
inline int power(int a, int b) {
  int ans = 1;
  while (b) {
    if (b & 1) ans = (long long)ans * a % mod;
    b >>= 1;
    a = (long long)a * a % mod;
  }
  return ans;
}
inline void doing() {
  for (int i = (n), _end_ = (1); i >= _end_; i--) {
    int x = p[i];
    if (!cnt[x]) {
      cnt[x] = 1;
      tag[x] = 1;
      ok[i] = 0;
    } else {
      ok[i] = 1;
      int u = x - 1;
      while (u > 1) {
        int t = d[u], sum = 0;
        while (!(u % t)) u /= t, sum++;
        if (cnt[t] < sum)
          cnt[t] = sum, tag[t] = 1;
        else if (cnt[t] == sum)
          tag[t]++;
      }
    }
  }
  int ad = 0;
  for (int i = (n), _end_ = (1); i >= _end_; i--) {
    int u = p[i] - ok[i], flg = 1;
    while (u > 1) {
      int t = d[u], sum = 0;
      while (!(u % t)) u /= t, sum++;
      if (tag[t] == 1 && cnt[t] == sum) flg = 0;
    }
    ad |= flg;
  }
  int ans = 1;
  for (int i = (1), _end_ = (2e6); i <= _end_; i++)
    if (cnt[i]) ans = (long long)ans * power(i, cnt[i]) % mod;
  printf("%d\n", (ans + ad) % mod);
}
int main() {
  prepare();
  init();
  doing();
  return 0;
}
