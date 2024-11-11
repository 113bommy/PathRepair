#include <bits/stdc++.h>
using namespace std;
vector<long long> vi[300005];
long long color[100005];
long long pa[500005];
long long si[500005];
bool visi[1000005] = {false};
bool is[100005];
long long fac[10000001];
long long prime[400005];
long long bit[100005];
void fact() {
  fac[0] = 1;
  for (long long i = 1; i <= 10000000; i++) {
    fac[i] = (fac[i - 1] * i) % 1000000007;
  }
  return;
}
void sieve() {
  prime[0] = 0;
  prime[1] = 0;
  for (long long i = 2; i < 400005; i++) {
    prime[i] = 1;
  }
  for (long long i = 2; i * i < 400005; i++) {
    if (prime[i] == 1) {
      for (long long j = i * i; j < 400005; j += i) {
        prime[j] = 0;
      }
    }
  }
}
long long power(long long n, long long p) {
  if (p == 0) return 1;
  long long res = power((n * n) % 1000000007, p / 2);
  if (p % 2 == 1) res = (n * res) % 1000000007;
  return res;
}
void upd(long long i, long long val, long long n) {
  for (; i <= n; i += i & (-i)) bit[i] += val;
}
long long qry(long long i) {
  long long sum = 0;
  for (; i > 0; i -= i & (-i)) sum += bit[i];
  return sum;
}
long long fin(long long u) {
  if (pa[u] == u) return u;
  return fin(pa[u]);
}
void uni(long long u, long long v) {
  long long p1 = fin(u);
  long long p2 = fin(v);
  if (p1 == p2) return;
  if (si[p1] < si[p2]) swap(p1, p2);
  si[p1] += si[p2];
  pa[p2] = p1;
  return;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long n, c;
  cin >> n >> c;
  long long ans = LLONG_MIN;
  for (long long i = 0; i < n; i++) {
    long long a, b;
    cin >> a >> b;
    long long x = a + c - b;
    if (b <= c) x = a;
    if (x > ans) ans = x;
  }
  cout << ans;
  return 0;
}
