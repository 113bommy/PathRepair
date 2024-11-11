#include <bits/stdc++.h>
using namespace std;
const long long maxn = 200019;
long long n, m, head[maxn], to[maxn * 2], nextt[maxn * 2], w[maxn * 2],
    tot = 1, vis[maxn], ans[maxn];
priority_queue<pair<long long, long long>, vector<pair<long long, long long> >,
               greater<pair<long long, long long> > >
    q;
void add(long long x, long long y, long long z) {
  w[tot] = z;
  to[tot] = y;
  nextt[tot] = head[x];
  head[x] = tot++;
}
int main() {
  scanf("%I64%I64", &n, &m);
  for (long long i = 1; i <= m; i++) {
    long long a, b, c;
    scanf("%I64%I64%I64", &a, &b, &c);
    add(a, b, 2 * c);
    add(b, a, 2 * c);
  }
  for (long long i = 1; i <= n; i++) {
    long long t;
    scanf("%I64", &t);
    q.push(make_pair(t, i));
  }
  while (!q.empty()) {
    pair<long long, long long> u = q.top();
    q.pop();
    if (vis[u.second]) continue;
    vis[u.second] = 1;
    ans[u.second] = u.first;
    for (long long i = head[u.second]; i; i = nextt[i]) {
      long long v = to[i];
      q.push(make_pair(u.first + w[i], v));
    }
  }
  for (long long i = 1; i <= n; i++) printf("%I64 ", ans[i]);
  return 0;
}
