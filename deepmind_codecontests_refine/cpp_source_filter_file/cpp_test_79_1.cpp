#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
void fileio(const string &s) {
  freopen((s + ".in").c_str(), "r", stdin);
  freopen((s + ".out").c_str(), "w", stdout);
}
const long long INF = 4e18;
inline long long read() {
  long long x = 0;
  bool flag = 1;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') flag = 0;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    x = (x << 1) + (x << 3) + c - '0';
    c = getchar();
  }
  return (flag ? x : ~(x - 1));
}
long long n, pre[300001], a[300001], b[300001];
array<long long, 2> t[600010];
vector<long long> G[300001];
array<long long, 2> p(array<long long, 2> x, array<long long, 2> y) {
  if (x[0] < y[0])
    return x;
  else
    return y;
}
void modify(long long x, long long v) {
  for (t[x += n][0] = v; x > 1; x >>= 1) t[x >> 1] = p(t[x], t[x ^ 1]);
}
array<long long, 2> query(long long l, long long r) {
  array<long long, 2> res = {INF, 0};
  for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
    if (l & 1) res = p(t[l++], res);
    if (r & 1) res = p(t[--r], res);
  }
  return res;
}
signed main() {
  n = read();
  for (long long i = 1; i <= n; i++) a[i] = read();
  for (long long i = 1; i <= n; i++) G[i + read()].push_back(i);
  n++;
  for (long long i = n; i < 2 * n; i++) t[i] = {INF, i - n};
  for (long long i = n - 1; i; i--) t[i] = p(t[i << 1], t[i << 1 | 1]);
  modify(0, 0);
  for (long long k = 0; k < 5; k++)
    for (long long i = 1; i < n; i++) {
      array<long long, 2> res = query(i - a[i], i + 1);
      res[0]++;
      for (long long l : G[i])
        if (t[l + n][0] > res[0]) {
          modify(l, res[0]);
          pre[l] = res[1];
        }
    }
  for (long long i = 1; i < n; i++) {
    array<long long, 2> res = query(i - a[i], i + 1);
    if (i == n - 1) {
      if (res[0] == INF) {
        puts("-1");
        return 0;
      }
      cout << res[0] + 1 << endl;
      long long x = res[1];
      while (x) {
        cout << x << " ";
        x = pre[x];
      }
      cout << 0 << endl;
      return 0;
    }
    res[0]++;
    for (long long l : G[i])
      if (t[l + n][0] > res[0]) {
        modify(l, res[0]);
        pre[l] = res[1];
      }
  }
  return 0;
}
