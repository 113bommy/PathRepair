#include <bits/stdc++.h>
using namespace std;
const int MAX = 2e5 + 1;
struct p {
  int x, y;
  bool operator<(const p &a) const {
    if (x != a.x) return x < a.x;
    return y < a.y;
  }
} po[MAX];
int q;
map<long long, set<p> > ma;
map<p, int> res;
set<p>::iterator A;
int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
p GCD(p a) {
  int Gcd = gcd(a.x, a.y);
  if (a.x || a.y) a.x /= Gcd, a.y /= Gcd;
  return a;
}
p operator+(p a, p b) { return GCD((p){a.x + b.x, a.y + b.y}); }
int main() {
  scanf("%d", &q);
  int tot = 0;
  for (int t, x, y, i = 1; i <= q; ++i) {
    scanf("%d%d%d", &t, &x, &y);
    p a = (p){x, y};
    a = GCD(a);
    long long dis = 1ll * x * x + 1ll * y * y;
    if (t == 1) {
      for (A = ma[dis].begin(); A != ma[dis].end(); ++A) res[*A + a] += 2;
      ma[dis].insert(a), ++res[a], ++tot;
    } else if (t == 2) {
      ma[dis].erase(a);
      for (A = ma[dis].begin(); A != ma[dis].end(); ++A) res[*A + a] -= 2;
      --res[a], --tot;
    } else if (t == 3)
      printf("%d\n", tot - res[a]);
  }
  return 0;
}
