#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
const int N = 101000;
const int INF = 0x3f3f3f3f;
void MOD(long long &a) {
  if (a >= mod) a -= mod;
}
void MOD(long long &a, long long c) {
  if (a >= c) a -= c;
}
void ADD(long long &a, long long b) {
  a += b;
  MOD(a);
}
void ADD(long long &a, long long b, long long c) {
  a += b;
  MOD(a, c);
}
long long qpow(long long a, long long b) {
  long long ans = 1;
  while (b) {
    if (b & 1) ans = ans * a % mod;
    a = a * a % mod;
    b /= 2;
  }
  return ans;
}
long long qpow(long long a, long long b, long long c) {
  long long ans = 1;
  while (b) {
    if (b & 1) ans = ans * a % c;
    a = a * a % c;
    b /= 2;
  }
  return ans;
}
int n;
struct ring {
  int a, b, h;
  bool operator<(const ring &x) const {
    if (b == x.b) return a > x.a;
    return b > x.b;
  }
} r[N];
long long ans = 0;
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d%d%d", &r[i].a, &r[i].b, &r[i].h);
  sort(r, r + n);
  stack<ring> s;
  long long now = 0;
  for (int i = 0; i < n; i++) {
    while (!s.empty() && s.top().a >= r[i].b) {
      now -= s.top().h;
      s.pop();
    }
    now += r[i].h;
    s.push(r[i]);
    ans = max(ans, now);
  }
  printf("%lld\n", ans);
}
