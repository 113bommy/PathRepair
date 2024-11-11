#include <bits/stdc++.h>
using namespace std;
template <typename T>
T read1() {
  T t = 0;
  char k;
  bool v = 0;
  do (k = getchar()) == '-' && (v = 1);
  while ('0' > k || k > '9');
  while ('0' <= k && k <= '9')
    t = (t << 3) + (t << 1) + (k ^ '0'), k = getchar();
  return v ? -t : t;
}
int f[200005], s, m;
int Find(int n) { return f[n] ^ n ? f[n] = Find(f[n]) : n; }
bool judge(int u, int v) { return Find(u) == Find(v); }
void Merge(int u, int v) { f[Find(u)] = Find(v); }
int qkpow(int n) {
  if (n < 63) return (1ll << n) % 1000000007;
  long long t = qkpow(n >> 1);
  t = t * t % 1000000007;
  if (n & 1) t = (t << 1) % 1000000007;
  return t;
}
int main() {
  s = read1<long long>(), m = read1<long long>();
  int t = s;
  for (int i = 1; i <= (s << 1); ++i) f[i] = i;
  for (int i = 1; i <= m; ++i) {
    int u = read1<long long>(), v = read1<long long>();
    if (!read1<long long>()) {
      if (judge(u, v) || judge(u + s, v + s)) return puts("0"), 0;
      if (!judge(u, v + s)) --t, Merge(u, v + s);
      Merge(u + s, v);
    } else {
      if (judge(u + s, v) || judge(u, v + s)) return puts("0"), 0;
      if (!judge(u, v)) --t, Merge(u, v);
      Merge(u + s, v + s);
    }
  }
  printf("%d\n", qkpow(t - 1));
  return 0;
}
