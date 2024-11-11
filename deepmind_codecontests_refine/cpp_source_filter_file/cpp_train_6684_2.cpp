#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5, mod = 998244353;
int n, ln, rn, m;
int C[maxn];
bool visit[maxn];
long long p[maxn], s[maxn];
int lower_bound(int x) { return x & (-x); }
void add(int x, int k) {
  for (int i = x; i <= n + 2; i += lower_bound(i)) {
    C[i] += k;
  }
}
int query(int x) {
  if (x <= 0) return 0;
  int sum = 0;
  while (x) {
    sum += C[x];
    x = x - lower_bound(x);
  }
  return sum;
}
void find(int x) {
  int mid, l = 1, r = x;
  while (l + 1 < r) {
    mid = (l + r) >> 1;
    if (query(r - 1) - query(mid - 1))
      l = mid;
    else
      r = mid;
  }
  ln = l;
  l = x + 1;
  r = n + 2;
  while (l + 1 < r) {
    mid = (l + r) >> 1;
    if (query(mid - 1) - query(l - 1))
      r = mid;
    else
      l = mid;
  }
  rn = l;
}
long long power(long long x, int k) {
  long long sum = 1;
  while (k) {
    if (k & 1) sum = sum * x % mod;
    k = k >> 1;
    x = x * x % mod;
  }
  return sum;
}
long long count(int l, int r) {
  return (s[l] - s[r] + mod) % mod * power(p[r], mod - 2) % mod;
}
int main() {
  int k, a, b;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) cin >> p[i], p[i] = power(p[i], mod - 2);
  p[n + 1] = 1;
  for (int i = n; i > 0; i--)
    p[i] = p[i + 1] * 100 % mod * p[i] % mod, s[i] = (s[i + 1] + p[i]) % mod;
  long long ans = s[1];
  for (int i = 1; i <= m; i++) {
    cin >> k;
    if (visit[k]) {
      add(k, -1);
      visit[k] = 0;
      find(k);
      ans = (ans - count(ln, k) - count(k, rn) + count(ln, rn) + mod) % mod;
      cout << ans << endl;
    } else {
      add(k, 1);
      visit[k] = 1;
      find(k);
      ans = (ans - count(ln, rn) + count(ln, k) + count(k, rn) + mod) % mod;
      cout << ans << endl;
    }
  }
  return 0;
}
