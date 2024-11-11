#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  long long res = 0;
  char c;
  bool zf = 0;
  while (((c = getchar()) < '0' || c > '9') && c != '-')
    ;
  if (c == '-')
    zf = 1;
  else
    res = c - '0';
  while ((c = getchar()) >= '0' && c <= '9')
    res = (res << 3) + (res << 1) + c - '0';
  if (zf) return -res;
  return res;
}
long long jc[19];
long long n, k, s;
long long data[26];
unordered_map<long long, long long> M[26];
long long ans;
void dfs1(long long now, long long _s, long long tot) {
  if (_s > s) return;
  if (now > n / 2) {
    M[tot][_s]++;
    return;
  }
  dfs1(now + 1, _s, tot);
  dfs1(now + 1, _s + data[now], tot);
  if (tot != k && data[now] <= 18) {
    dfs1(now + 1, _s + jc[data[now]], tot + 1);
  }
  return;
}
void dfs2(long long now, long long _s, long long tot) {
  if (_s > s) return;
  if (now > n) {
    for (register long long i = 0; i <= k - tot; i++) {
      ans += M[i][s - _s];
    }
    return;
  }
  dfs2(now + 1, _s, tot);
  dfs2(now + 1, _s + data[now], tot);
  if (tot != k && data[now] <= 18) {
    dfs2(now + 1, _s + jc[data[now]], tot + 1);
  }
  return;
}
signed main() {
  n = read(), k = read(), s = read();
  for (register long long i = 1; i <= n; i++) {
    data[i] = read();
  }
  jc[0] = 1;
  for (register long long i = 1; i <= 18; i++) {
    jc[i] = jc[i - 1] * i;
  }
  dfs1(1, 0, 0);
  dfs2(n / 2 + 1, 0, 0);
  cout << ans << '\n';
  return 0;
}
