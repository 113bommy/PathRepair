#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e5 + 10;
const int P = 998244353;
int n, k;
struct Node {
  int l, r;
  bool operator<(const Node& rhs) const {
    return l < rhs.l || (l == rhs.l && r < rhs.r);
  }
} p[maxn];
int fac[maxn];
int Pow(int a, int b) {
  long long sum = 1, z = a;
  for (; b; b >>= 1) {
    if (b & 1) sum = sum * z % P;
    if (b) z = z * z % P;
  }
  return (int)sum;
}
int inv(int x) { return Pow(x, P - 2); }
int c(int a, int b) {
  if (a < b) return 0;
  return 1LL * fac[a] * inv(fac[b]) % P * inv(fac[a - b]) % P;
}
multiset<int> s;
int main() {
  fac[0] = 1;
  for (int i = 1; i < maxn; ++i) fac[i] = 1LL * i * fac[i - 1] % P;
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= n; ++i) scanf("%d%d", &p[i].l, &p[i].r);
  if (k == 1) {
    printf("%d\n", n);
    return 0;
  }
  sort(p + 1, p + n + 1);
  s.insert(p[1].r);
  long long ans = 0;
  for (int i = 2; i <= n; ++i) {
    while (!s.empty() && *s.begin() < p[i].l) s.erase(s.begin());
    int len = s.size();
    ans = (ans + c(len, k - 1)) % P;
    s.insert(p[i].r);
  }
  printf("%lld\n", ans);
}
