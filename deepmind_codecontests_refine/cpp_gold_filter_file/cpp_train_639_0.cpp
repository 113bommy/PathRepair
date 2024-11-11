#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 2e5 + 100;
struct node {
  int x;
  char y;
};
struct rule {
  bool operator()(const node &a1, const node &a2) { return a1.x < a2.x; }
};
long long a[maxn];
int main() {
  long long n, m, k, f = 0, tot = 0, kk = 1;
  scanf("%lld %lld %lld", &n, &m, &k);
  for (int i = 0; i < m; i++) {
    long long x;
    scanf("%lld", &a[i]);
    if (f == 0) {
      tot++;
      kk = ((a[i] - kk) / k) * k + 1;
      f = 1;
    } else {
      if ((a[i] - kk - i + f) >= k) {
        tot++;
        a[i] -= i;
        kk = ((a[i] - 1) / k) * k + 1;
        f = 1;
      } else {
        a[i] -= (i - f);
        f++;
      }
    }
  }
  printf("%lld\n", tot);
}
