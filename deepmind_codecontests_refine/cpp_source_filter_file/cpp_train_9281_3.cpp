#include <bits/stdc++.h>
using namespace std;
const int maxn = 500010;
const long long mod = 1000000007;
long long a[maxn], p[maxn];
long long n;
class BIT {
 public:
  long long tr[maxn];
  void add(int x, long long y) {
    for (; x <= n; x += (x & (-x))) {
      tr[x] += y;
      tr[x] %= mod;
    }
  }
  long long ask(int x) {
    long long ans = 0;
    for (; x; x -= (x & (-x))) {
      ans += tr[x];
      ans %= mod;
    }
    return ans;
  }
};
BIT t1, t2;
bool cmp(int x, int y) { return a[x] < a[y]; }
int main() {
  scanf("%lld", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%lld", &a[i]);
    p[i] = i;
  }
  long long ans = 0;
  sort(p + 1, p + 1 + n, cmp);
  for (int i = 1; i <= n; i++) {
    long long now = p[i];
    ans = (ans + (a[now] * ((n - now + 1) * now) % mod) % mod) % mod;
    ans = (ans + (a[now] *
                  ((t1.ask(now) * (n - now + 1)) % mod +
                   (t2.ask(n - now + 1) * now) % mod) %
                  mod) %
                     mod) %
          mod;
    t1.add(now, now);
    t2.add(n - now + 1, n - now + 1);
  }
  printf("%lld\n", ans);
}
