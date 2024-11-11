#include <bits/stdc++.h>
using namespace std;
const int N = 200005;
int n;
long long s, f[N], g[N];
struct data {
  long long v, c;
  long long f(long long x) { return x * v + c; }
  long long get(long long x) { return (x - c + v - 1) / v; }
  bool operator<(const data& b) const { return c ^ b.c ? c < b.c : v > b.v; }
} a[N], q[N];
int main() {
  cin >> n >> s;
  for (int i = 1; i <= n; ++i) {
    scanf("%lld%lld", &a[i].v, &a[i].c);
    if (a[i].c >= s) {
      --i, --n;
      continue;
    }
  }
  sort(a + 1, a + 1 + n);
  int nn = 0;
  for (int i = 1; i <= n; ++i)
    if (a[i].v > a[nn].v) a[++nn] = a[i];
  n = nn;
  a[++n] = (data){0x3f3f3f3f, s};
  int he = 1, ta = 1;
  q[1] = (data){a[1].v, 0};
  for (int i = 2; i <= n; ++i) {
    while (he < ta) {
      int k1 = q[he].get(a[i].c), k2 = q[he + 1].get(a[i].c);
      if (k1 > k2 || (k1 == k2 && q[he].f(k1) <= q[he + 1].f(k2)))
        ++he;
      else
        break;
    }
    f[i] = q[he].get(a[i].c), g[i] = q[he].f(f[i]) - a[i].c;
    data k1 = (data){a[i].v, g[i] - f[i] * a[i].v};
    while (ta > he && (k1.c - q[ta].c) * (q[ta - 1].v - q[ta].v) <=
                          (q[ta - 1].c - q[ta].c) * (k1.v - q[ta].v))
      --ta;
    q[++ta] = k1;
  }
  cout << f[n] << endl;
  return 0;
}
