#include <bits/stdc++.h>
using namespace std;
const int maxx = 1e6 + 2;
struct S {
  int a, b;
  bool operator<(const S& x) const { return (b - a) < (x.b - x.a); }
};
S c[maxx];
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d%d", &c[i].a, &c[i].b);
  }
  sort(c + 1, c + 1 + n);
  long long ans = 0;
  for (int i = 1; i <= n; i++) {
    ans = ans + 1ll * c[i].a * (i - 1) + 1ll * c[i].b * (n - i);
  }
  printf("%lld\n", ans);
}
