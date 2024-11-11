#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vl = vector<ll>;
using vii = vector<pii>;
using vll = vector<pll>;
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }
vector<int> sieve;
void calc_sieve(int n) {
  sieve.reserve(n + 1);
  for (int i = 0, nnnn = (n + 1); i < nnnn; ++i) sieve[i] = i;
  for (int i = 2, nnnn = (n + 1); i < nnnn; ++i) {
    if (sieve[i] == i) {
      for (ll j = i * i; j <= n; j += i) {
        if (sieve[j] == j) sieve[j] = i;
      }
    }
  }
}
ll norm(ll a, ll P) {
  while (a >= P) a -= P;
  while (a < 0) a += P;
  return a;
}
ll mul_mod(ll a, ll b, ll P) { return a * b % P; }
ll pow_mod(ll a, ll b, ll P) {
  ll curr = a, ans = 1;
  while (b != 0) {
    if (b & 1) {
      ans *= curr;
      ans %= P;
    }
    curr *= curr;
    curr %= P;
    b >>= 1;
  }
  return ans;
}
ll inv_mod(ll a, ll P) { return pow_mod(a, P - 2ll, P); }
ll div_mod(ll a, ll b, ll P) { return a * inv_mod(b, P) % P; }
int msb(ll a) {
  for (int i = 62; i >= 0; i--) {
    if (a & ((ll)1 << i)) return i + 1;
  }
  return 0;
}
vector<ll> fact;
void calc_fact(int n, ll P) {
  if (fact.size() < 1) fact.push_back(1);
  for (int i = fact.size(), nnnn = (n + 1); i < nnnn; ++i)
    fact.push_back(fact[i - 1] * i % P);
}
vector<ll> fact_inv;
void calc_fact_inv(int n, ll P) {
  if (fact_inv.size() < 1) fact_inv.push_back(1);
  for (int i = fact_inv.size(), nnnn = (n + 1); i < nnnn; ++i)
    fact_inv.push_back(fact_inv[i - 1] * inv_mod(i, P) % P);
}
ll nCr(int n, int r, ll P) {
  if (r > n) return 0;
  calc_fact(n, P);
  calc_fact_inv(n, P);
  return (fact[n] * fact_inv[r] % P) * fact_inv[n - r] % P;
}
ll nCr_inv(int n, int r, ll P) {
  if (r > n) return 0;
  calc_fact(n, P);
  calc_fact_inv(n, P);
  return (fact_inv[n] * fact[r] % P) * fact[n - r] % P;
}
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const long double eps = 1e-9;
const long long mod = 1000000007;
const int MAXN = 100000;
void solve() {
  int n, m;
  cin >> n >> m;
  int p[n], diff[n];
  for (int i = 0, nnnn = (n); i < nnnn; ++i) {
    cin >> p[i], diff[i] = p[i] - i - 1;
    if (diff[i] < 0) diff[i] += n;
  }
  int cnt[n];
  memset(cnt, 0, sizeof cnt);
  for (int i = 0, nnnn = (n); i < nnnn; ++i) cnt[diff[i]]++;
  int ans = 0;
  for (int i = 0, nnnn = (n); i < nnnn; ++i) {
    if (n - cnt[i] <= m * 2) {
      int diff1[n], count = 0;
      for (int j = 0, nnnn = (n); j < nnnn; ++j) diff1[j] = diff[j];
      int j = 0;
      while (j < n) {
        if (diff1[j] % n != i) {
          int pos = (j + n + diff1[j] - i) % n;
          diff1[j] = (diff1[pos] + n - j + pos) % n;
          diff1[pos] = 1;
          count++;
        }
        if (diff1[j] == i) j++;
      }
      if (count <= m) ans++;
    }
  }
  cout << ans << ' ';
  if (n - cnt[0] <= m * 2) {
    int diff1[n], count = 0;
    for (int j = 0, nnnn = (n); j < nnnn; ++j) diff1[j] = diff[j];
    int j = 0;
    while (j < n) {
      if (diff1[j] % n != 0) {
        int pos = (j + n + diff1[j] - 0) % n;
        diff1[j] = (diff1[pos] + n - j + pos) % n;
        diff1[pos] = 1;
        count++;
      }
      if (diff1[j] == 0) j++;
    }
    if (count <= m) cout << 0 << ' ';
  }
  for (int i = n - 1; i >= 1; i--) {
    if (n - cnt[i] <= m * 2) {
      int diff1[n], count = 0;
      for (int j = 0, nnnn = (n); j < nnnn; ++j) diff1[j] = diff[j];
      int j = 0;
      while (j < n) {
        if (diff1[j] % n != i) {
          int pos = (j + n + diff1[j] - i) % n;
          diff1[j] = (diff1[pos] + n - j + pos) % n;
          diff1[pos] = 1;
          count++;
        }
        if (diff1[j] == i) j++;
      }
      if (count <= m) cout << n - i << ' ';
    }
  }
  cout << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout << setprecision(12) << fixed;
  int t;
  cin >> t;
  while (t--) solve();
}
