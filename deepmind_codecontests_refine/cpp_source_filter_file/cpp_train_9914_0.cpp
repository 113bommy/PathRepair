#include <bits/stdc++.h>
using namespace std;
struct P {
  int x, y;
  bool operator<(const P &a) const { return y < a.y; };
};
int a, b, c, d, i, k, n, m, e, dx[10] = {1, 0, -1, 0, 1, 1, -1, -1},
                               dy[10] = {0, 1, 0, -1, 1, -1, 1, -1};
int o[500101];
long long l[500101];
long long j[500101];
long long x, y, z, mod = 1000000009 * 1000000007;
char r[1];
P u[1];
queue<int> q;
stack<int> s;
map<long long, long long> p;
vector<int> v;
bool as(P a, P b) { return a.x > b.x; }
long long gcd(long long x, long long y) {
  if (y == 0) return x;
  return gcd(y, x % y);
}
int main() {
  o[0] = 1;
  for (int t = 1; t <= 500000; t++) o[t] = o[t - 1] * 2 % mod;
  scanf("%d", &e);
  for (int tt = 1; tt <= e; tt++) {
    p.clear();
    scanf("%d %d", &a, &b);
    for (int t = 1; t <= a; t++) scanf("%lld", &l[t]);
    for (int t = 1; t <= b; t++) {
      scanf("%d %d", &n, &m);
      q.push(m);
      j[m] += o[n - 1];
      j[m] %= mod;
    }
    for (int t = 1; t <= a; t++) p[j[t]] += l[t];
    x = 0;
    for (int t = 1; t <= a; t++)
      if (j[t]) x = gcd(x, p[j[t]]);
    printf("%lld\n", x);
    for (; q.size(); q.pop()) j[q.front()] = 0;
  }
}
