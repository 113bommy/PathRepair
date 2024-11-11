#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) {
  if (a < 0) a = -a;
  if (b < 0) b = -b;
  return b == 0 ? a : gcd(b, a % b);
}
template <typename T>
void read(T &res) {
  bool flag = false;
  char ch;
  while (!isdigit(ch = getchar())) (ch == '-') && (flag = true);
  for (res = ch - 48; isdigit(ch = getchar());
       res = (res << 1) + (res << 3) + ch - 48)
    ;
  flag && (res = -res);
}
long long lcm(long long a, long long b) { return a * b / gcd(a, b); }
long long qp(long long a, long long b, long long mod) {
  long long ans = 1;
  if (b == 0) {
    return ans % mod;
  }
  while (b) {
    if (b % 2 == 1) {
      b--;
      ans = ans * a % mod;
    }
    a = a * a % mod;
    b = b / 2;
  }
  return ans % mod;
}
long long qpn(long long a, long long b, long long p) {
  long long ans = 1;
  a %= p;
  while (b) {
    if (b & 1) {
      ans = (ans * a) % p;
      --b;
    }
    a = (a * a) % p;
    b >>= 1;
  }
  return ans % p;
}
const long long mod = 998244353;
const long long N = 1e5 + 7;
struct node {
  long long x, y, d;
  bool operator<(const node &a) const { return d < a.d; }
};
long long solve(long long a, long long b) {
  long long x = a / b;
  long long y = a % b;
  return x * x * (b - y) + y * (x + 1) * (x + 1);
}
priority_queue<node> q;
signed main() {
  long long n, k;
  read(n);
  read(k);
  long long ans = 0;
  for (long long i = 1; i <= n; ++i) {
    long long x;
    read(x);
    q.push(node{x, 1, solve(x, 1) - solve(x, 2)});
    ans += x * x;
  }
  for (long long i = n; i <= k; i++) {
    node top = q.top();
    q.pop();
    ans -= top.d;
    q.push(node{top.x, top.y + 1,
                solve(top.x, top.y + 1) - solve(top.x, top.y + 2)});
  }
  printf("%lld\n", ans);
  return 0;
}
