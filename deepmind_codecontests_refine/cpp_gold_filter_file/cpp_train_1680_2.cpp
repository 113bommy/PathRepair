#include <bits/stdc++.h>
using namespace std;
const int N = 1e3;
struct Node {
  long long a, b, c;
} a[N];
long long f[N], n;
bool Cmp(const Node& a, const Node& b) { return a.b > b.b; }
int main() {
  scanf("%lld", &n);
  for (int i = 1; i <= n; i++) scanf("%lld%lld%lld", &a[i].a, &a[i].b, &a[i].c);
  sort(a + 1, a + 1 + n, Cmp);
  for (int i = 1; i <= n; i++)
    for (int j = i; j >= 0; j--) {
      f[j] = max(f[j], f[j] + a[i].a - a[i].b * a[i].c);
      if (j) f[j] = max(f[j], f[j - 1] + a[i].a - a[i].b * (j - 1));
    }
  long long mx = 0;
  for (int i = 0; i <= n; i++) mx = max(f[i], mx);
  printf("%lld\n", mx);
}
