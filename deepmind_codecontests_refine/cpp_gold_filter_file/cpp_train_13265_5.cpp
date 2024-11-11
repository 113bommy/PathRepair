#include <bits/stdc++.h>
using namespace std;
const int MAXN = 3e4, MAXP = 4e4;
const int MOD = 1e9 + 7;
bool prime[MAXP + 5];
int fact[MAXN + 5], invfact[MAXN + 5];
int cnt[MAXP + 5];
vector<pair<int, int>> myst;
vector<int> primes;
int n, a, ans = 1;
int add(int a, int b) {
  int c = a + b;
  if (c >= MOD) {
    c -= MOD;
  }
  return c;
}
int mul(int a, int b) { return 1LL * a * b % MOD; }
int pwr(int a, int b) {
  if (!b) {
    return 1;
  }
  int res = pwr(a, b >> 1);
  res = mul(res, res);
  if (b & 1) {
    res = mul(res, a);
  }
  return res;
}
int inv(int a) { return pwr(a, MOD - 2); }
int C(int a, int b) {
  int res = fact[b];
  res = mul(res, invfact[a]);
  res = mul(res, invfact[b - a]);
  return res;
}
void ex(int a) {
  for (int i = 0; i < myst.size(); i++) {
    if (myst[i].first == a) {
      myst[i].second++;
      return;
    }
  }
  myst.push_back({a, 1});
}
void count_log_number(int a) {
  for (int i = 0; i < primes.size(); i++) {
    int count = 0;
    while (a % primes[i] == 0) {
      count++;
      a /= primes[i];
    }
    cnt[primes[i]] += count;
  }
  if (a != 1) {
    ex(a);
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  memset(prime, 1, sizeof prime);
  prime[1] = false;
  for (int i = 2; i <= MAXP; i++) {
    if (prime[i]) {
      primes.push_back(i);
      for (long long j = 1LL * i * i; j <= MAXP; j += i) {
        prime[j] = false;
      }
    }
  }
  fact[0] = 1;
  for (int i = 1; i <= MAXN; i++) {
    fact[i] = mul(fact[i - 1], i);
  }
  for (int i = 0; i <= MAXN; i++) {
    invfact[i] = inv(fact[i]);
  }
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a;
    count_log_number(a);
  }
  for (int i = 2; i <= MAXP; i++) {
    int res = C(n - 1, cnt[i] + n - 1);
    ans = mul(ans, res);
  }
  for (int i = 0; i < myst.size(); i++) {
    int res = C(n - 1, myst[i].second + n - 1);
    ans = mul(ans, res);
  }
  cout << ans;
}
