#include <bits/stdc++.h>
using namespace std;
string tostr(long long n) {
  stringstream rr;
  rr << n;
  return rr.str();
}
long long binpow(long long n, long long p) {
  if (p == 0) return 1LL;
  if (p % 2 == 0) {
    long long res = binpow(n, p / 2);
    return res * res;
  }
  return n * binpow(n, p - 1);
}
long long qpow(long long n, long long k) {
  long long ans = 1;
  assert(k >= 0);
  n %= 1000000007;
  while (k > 0) {
    if (k & 1) ans = (ans * n) % 1000000007;
    n = (n * n) % 1000000007;
    k >>= 1;
  }
  return ans % 1000000007;
}
long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a % b); }
long long lcm(long long a, long long b) { return a * (b / gcd(a, b)); }
long long par[100005], Size[100005];
bool is_lucky(long long w) {
  string s = tostr(w);
  for (int i = 0; i < s.size(); i++) {
    if (s[i] != '4' && s[i] != '7') return false;
  }
  return true;
}
void Set(long long n) {
  for (int i = 1; i <= n; i++) par[i] = i, Size[i] = 1;
}
long long Find(long long x) {
  if (x != par[x])
    return par[x] = Find(par[x]);
  else
    return x;
}
void Union(long long a, long long b) {
  long long x = Find(a), y = Find(b);
  if (x == y) return;
  if (Size[x] > Size[y]) swap(x, y);
  par[x] = y;
  Size[y] += Size[x];
}
int main() {
  ios_base::sync_with_stdio(false);
  int n;
  cin >> n;
  Set(n);
  for (int i = 1; i < n; i++) {
    long long u, v, w;
    cin >> u >> v >> w;
    if (!is_lucky(w)) {
      Union(u, v);
    }
  }
  long long ans = 0;
  for (int i = 1; i <= n; i++) {
    long long sum = Size[par[i]];
    sum = n - sum;
    ans += sum * (sum - 1);
  }
  cout << ans << "\n";
  return 0;
}
