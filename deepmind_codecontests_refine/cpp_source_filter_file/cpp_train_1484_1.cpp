#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;
const int INF = 1e9;
const ll LINF = 1e18;
const int MAX_N = 1e5 + 1;
const double eps = 1e-9;
bool isPrime(long long n) {
  if (n == 1) return false;
  if (n == 2) return true;
  for (long long i = 2; i * i <= n; i++) {
    if (n % i == 0) return false;
  }
  return true;
}
ll qexp(ll a, ll b) {
  ll res = 1;
  while (b) {
    if (b & 1) res = res * a;
    a = a * a;
    b >>= 1;
  }
  return res;
}
void solve() {
  long long n;
  cin >> n;
  vector<long long> v(n);
  for (auto &i : v) cin >> i;
  map<long long, vector<long long>> m;
  for (auto i : v) {
    for (long long j = 2; j * j <= i; j++) {
      long long cnt = 0;
      if (i % j == 0) {
        while (i % j == 0) {
          cnt++;
          i /= j;
        }
        m[j].push_back(cnt);
      }
    }
    if (i > 1) m[i].push_back(1);
  }
  long long ans = 1;
  for (auto i : m) {
    if (i.second.size() == n) {
      sort(i.second.begin(), i.second.end());
      ans *= qexp(i.first, i.second[1]);
    } else if (i.second.size() == n - 1) {
      sort(i.second.begin(), i.second.end());
      ans *= qexp(i.first, i.second[1]);
    }
  }
  cout << ans << "\n";
}
int32_t main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  long long tc = 1;
  for (long long t = 1; t <= tc; t++) {
    solve();
  }
  return 0;
}
