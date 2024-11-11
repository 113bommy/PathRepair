#include <bits/stdc++.h>
using namespace std;
long long fac[1000006];
inline long long exp(long long x, long long n) {
  long long r = 1;
  x = x % 1000000000000000000;
  while (n) {
    if (n % 2) r = (r * x) % 1000000000000000000;
    x = (x * x) % 1000000000000000000;
    n = n / 2;
  }
  return r;
}
inline long long mmi(long long a) {
  return exp(a, 1000000000000000000 - 2) % 1000000000000000000;
}
inline long long fact(long long n) {
  long long res = 1;
  for (long long i = 1; i < (n + 1); ++i) {
    res = (res * i) % 1000000000000000000;
  }
  return res;
}
inline void fact_a() {
  fac[0] = 1;
  fac[1] = 1;
  for (long long i = 1; i < (105); ++i) {
    fac[i] = (fac[i - 1] * i) % 1000000000000000000;
  }
}
inline long long inv_fact(long long n) {
  long long par = fac[n];
  long long res = mmi(par);
  return res;
}
inline long long comb(long long n, long long r) {
  if (n == r && r == 0) return 1;
  if (n < r) return 0;
  return ((fac[n] * inv_fact(r)) % 1000000000000000000 * inv_fact(n - r)) %
         1000000000000000000;
}
struct triplet {
  long long a, b, c;
};
bool operator<(const triplet &t1, const triplet &t2) {
  if (t1.a < t2.a) return true;
  if (t1.a == t2.a && t1.b < t2.b) return true;
  if (t1.a == t2.a && t1.b == t2.b && t1.c < t2.c) return true;
  return false;
}
pair<long long, pair<long long, long long> > ex_gcd(long long a, long long b) {
  if (b == 0) {
    return make_pair(a, make_pair(1, 0));
  }
  pair<long long, pair<long long, long long> > p = ex_gcd(b, a % b);
  long long gcd = p.first;
  long long x1 = p.second.first;
  long long y1 = p.second.second;
  long long x = y1;
  long long y = x1 - (a / b) * y1;
  return make_pair(gcd, make_pair(x, y));
}
long long prime[1000006];
long long spf_prime[1000006];
void sieve() {
  for (long long i = 2; i * i <= 1000000; i++)
    if (prime[i] == 0)
      for (long long j = i * i; j <= 1000000; j += i) prime[j] = 1;
}
void spf() {
  for (long long i = 2; i * i <= 1000000; i++)
    if (!spf_prime[i])
      for (long long j = i * i; j <= 1000000; j += i)
        if (!spf_prime[j]) spf_prime[j] = i;
  for (long long i = 2; i <= 1000000; i++)
    if (!spf_prime[i]) spf_prime[i] = i;
}
long long getparent_BIT(long long idx) { return idx - (idx & -idx); }
long long getnext_BIT(long long idx) { return idx + (idx & -idx); }
long long getsum_BIT(long long idx, long long BIT[], long long n) {
  long long sum = 0;
  while (idx > 0) {
    sum += BIT[idx];
    idx = getparent_BIT(idx);
  }
  return sum;
}
void update_BIT(long long idx, long long BIT[], long long val, long long n) {
  while (idx <= n) {
    BIT[idx] += val;
    idx = getnext_BIT(idx);
  }
}
void build_BIT(long long BIT[], long long a[], long long n) {
  for (long long i = 0; i < (n); ++i) {
    update_BIT(i, BIT, a[i], n);
  }
}
void comp_lps(string s, long long lps[], long long n) {
  long long i = 1, j = 0;
  while (i < n) {
    if (s[i] == s[j]) {
      lps[i++] = ++j;
    } else {
      if (j != 0)
        j = lps[j - 1];
      else
        lps[i++] = 0;
    }
  }
}
void dfs_l(long long u, vector<vector<long long> > &adj, long long status[]) {
  if (status[u] == 1) return;
  status[u] = 1;
  for (long long i = 0; i < (adj[u].size()); ++i) dfs_l(adj[u][i], adj, status);
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  spf();
  long long n, k;
  cin >> n >> k;
  long long cnt = 0;
  vector<long long> v;
  for (long long i = 1; i * i <= n; i++) {
    if (n % i == 0) {
      cnt++;
      if (cnt == k) {
        cout << i << "\n";
        return 0;
      }
      if (i * i != n) v.push_back(n / i);
    }
  }
  long long req = k - cnt;
  sort(v.begin(), v.end());
  if (v.size() <= req) {
    cout << -1 << "\n";
  } else {
    cout << v[req - 1] << "\n";
  }
}
