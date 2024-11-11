#include <bits/stdc++.h>
using namespace std;
const int maxn = 200010;
int n, m;
long long S, T, d;
int ban[maxn], p[maxn];
long long t[maxn], k[maxn], top[maxn], ans[maxn];
vector<int> v[maxn];
vector<int>::iterator vi;
set<long long> s;
set<long long>::iterator si;
long long exgcd(long long a, long long b, long long &x, long long &y) {
  if (!b) {
    x = 1, y = 0;
    return a;
  }
  long long ret = exgcd(b, a % b, x, y), t = x;
  x = y, y = t - a / b * x;
  return ret;
}
long long gcd(long long a, long long b) { return !b ? a : gcd(b, a % b); }
inline bool cmp(const int &a, const int &b) {
  return (t[a] % d == t[b] % d) ? (a < b) : (t[a] % d < t[b] % d);
}
inline int rd() {
  int ret = 0, f = 1;
  char gc = getchar();
  while (gc < '0' || gc > '9') {
    if (gc == '-') f = -f;
    gc = getchar();
  }
  while (gc >= '0' && gc <= '9') ret = ret * 10 + (gc ^ '0'), gc = getchar();
  return ret * f;
}
int main() {
  T = rd(), n = rd();
  int i;
  S = rd();
  for (i = 2; i <= n; i++) t[i] = rd(), S += t[i], t[i] += t[i - 1];
  long long x, y, b;
  d = exgcd(S, T, x, y);
  b = T / d, x = (x % b + b) % b;
  for (i = 1; i <= n; i++) {
    if (s.find(t[i] % T) != s.end())
      ban[i] = 1;
    else
      s.insert(t[i] % T), p[++p[0]] = i;
  }
  if (S % T == 0) {
    for (i = 1; i <= n; i++) printf("%d ", 1 - ban[i]);
    return 0;
  }
  sort(p + 1, p + p[0] + 1, cmp);
  for (i = 1; i <= p[0]; i++) {
    if (i == 1 || t[p[i]] % d != t[p[i - 1]] % d) m++;
    v[m].push_back(i);
  }
  for (i = 1; i <= m; i++) {
    s.clear();
    for (vi = v[i].begin(); vi != v[i].end(); vi++) {
      k[*vi] = x * (t[*vi] / d % b) % b;
      if (s.find(k[*vi]) != s.end())
        ban[*vi] = 1;
      else
        s.insert(k[*vi]);
    }
    for (vi = v[i].begin(); vi != v[i].end(); vi++) {
      si = s.upper_bound(k[*vi]);
      if (si == s.end())
        si = s.begin(), ans[*vi] = (*si) + b - k[*vi];
      else
        ans[*vi] = (*si) - k[*vi];
    }
  }
  for (i = 1; i <= n; i++) printf("%lld ", ans[i]);
  return 0;
}
