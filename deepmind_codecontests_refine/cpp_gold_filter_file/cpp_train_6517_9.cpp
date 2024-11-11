#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9 + 231;
int n, a[100001], ss, tr[100001];
pair<int, int> t[1 << 18];
long long ans;
void ustaw(int a, int x) {
  t[a + (1 << 17)] = make_pair(x, a);
  a += 1 << 17;
  a >>= 1;
  while (a) t[a] = min(t[a + a], t[a + a + 1]), a >>= 1;
}
pair<int, int> minx(int a, int b) {
  a += (1 << 17) - 1;
  b += (1 << 17) + 1;
  pair<int, int> ret = make_pair(inf, inf);
  while (a + 1 < b) {
    if (!(a & 1)) ret = min(ret, t[a + 1]);
    if (b & 1) ret = min(ret, t[b - 1]);
    a >>= 1;
    b >>= 1;
  }
  return ret;
}
void dodaj(int a, int x) {
  while (a <= n) tr[a] += x, a += a & -a;
}
int sum(int a, int b) {
  int ret = 0;
  a--;
  while (b) ret += tr[b], b -= b & -b;
  while (a) ret -= tr[a], a -= a & -a;
  return ret;
}
int main() {
  scanf("%d", &n) ?: 0;
  for (int i = (1); i <= (n); ++i)
    scanf("%d", &a[i]) ?: 0, ustaw(i, a[i]), dodaj(i, 1);
  ss = 1;
  for (int i = 0; i < (n); ++i) {
    pair<int, int> u = minx(ss, n), v = minx(1, ss - 1);
    if (u.first <= v.first)
      ustaw(u.second, inf), ans += sum(ss + 1, u.second), dodaj(u.second, -1),
          ss = u.second;
    else
      ustaw(v.second, inf), ans += sum(ss + 1, n) + sum(1, v.second),
          dodaj(v.second, -1), ss = v.second;
  }
  printf("%lld", ans + 1);
}
