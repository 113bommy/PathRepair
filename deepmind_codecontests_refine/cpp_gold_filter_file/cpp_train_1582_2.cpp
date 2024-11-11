#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
using vec = vector<int>;
using pii = pair<int, int>;
int read() {
  int x = 0;
  bool f = 0;
  char ch = getchar();
  while (!isdigit(ch)) f |= ch == '-', ch = getchar();
  while (isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
  return f ? -x : x;
}
const int N = 2010;
int n, a[N], b[N], lg[65537], U, sa, K;
bitset<N> f[65537];
priority_queue<pii> q;
void dfs(int st, int res) {
  if (!st) return;
  vec bit;
  for (int i = 0; i < n; i++)
    if (st >> i & 1) bit.push_back(i);
  for (; res * K <= sa && f[st][res * K]; res *= K)
    for (auto x : bit) b[x]++;
  for (int t = st; t; t -= t & -t) {
    int x = lg[t & -t];
    if (res >= a[x] && f[st ^ (1 << x)][res - a[x]]) {
      dfs(st ^ (1 << x), res - a[x]);
      return;
    }
  }
}
int main() {
  n = read();
  K = read();
  for (int i = 0; i < n; i++) a[i] = read(), sa += a[i];
  for (int i = 2; i < 1 << n; i++) lg[i] = lg[i >> 1] + 1;
  f[0][0] = 1;
  U = 1 << n;
  for (int s = 0; s < U; s++) {
    for (int t = s; t; t -= t & -t) {
      int x = lg[t & -t];
      f[s] |= f[s ^ (1 << x)] << a[x];
    }
    for (int t = sa / K; t; t--)
      if (f[s][t * K]) f[s][t] = 1;
  }
  if (!f[U - 1][1]) return puts("NO"), 0;
  puts("YES");
  dfs(U - 1, 1);
  for (int i = 0; i < n; i++) q.push(pii(b[i], a[i]));
  while (q.size() > 1) {
    pii x = q.top();
    q.pop();
    pii y = q.top();
    q.pop();
    printf("%d %d\n", x.second, y.second);
    x.second += y.second;
    while (x.second % K == 0) x.second /= K, x.first--;
    q.push(x);
  }
  return 0;
}
