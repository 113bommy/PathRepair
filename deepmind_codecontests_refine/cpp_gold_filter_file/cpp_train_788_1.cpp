#include <bits/stdc++.h>
using namespace std;
using uint = unsigned int;
using ll = long long;
const int M = 1e9 + 7;
const ll MLL = 1e18L + 9;
#pragma unused(M)
#pragma unused(MLL)
template <ostream& out = cout, class... T>
void prints(T&&...) {}
template <ostream& out = cout, class... T>
void printd(T&&...) {}
template <ostream& out = cout, class... T>
void printb(T&&...) {}
template <ostream& out = cout, class... T>
void printArr(T&&...) {}
ll modPow(ll base, ll ex, ll m) {
  ll ret = 1;
  while (ex) {
    if (ex & 1) {
      ret = ret * base % m;
    }
    ex >>= 1;
    base = base * base % m;
  }
  return ret;
}
ll modFact(ll n, ll m) {
  if (!n) {
    return 1;
  }
  static vector<ll> memo = {1, 1};
  if (n < (ll)memo.size()) {
    return memo[n];
  }
  for (int i = memo.size(); i <= n; i++) {
    memo.push_back(memo.back() * i % m);
  }
  return memo[n];
}
pair<ll, pair<ll, ll>> exGCD(ll a, ll b) {
  bool inv = false;
  if (a < b) {
    swap(a, b);
    inv = true;
  }
  vector<ll> r = {a, b}, ks;
  while (b) {
    ks.push_back(a / b);
    r.push_back(a = a % b);
    swap(a, b);
  }
  ll gcd = a;
  ll x = 0, y = 1, u = 1, v = -ks[0];
  for (unsigned long i = 1; i < ks.size(); i++) {
    ll k = ks[i];
    ll x2 = u, y2 = v, u2 = x - k * u, v2 = y - k * v;
    x = x2;
    y = y2;
    u = u2;
    v = v2;
  }
  if (inv) {
    swap(x, y);
  }
  return {gcd, {x, y}};
}
ll modInv(ll n, ll m) {
  return modPow(n, m - 2, m);
  auto p = exGCD(n, m);
  return (p.second.first + m) % m;
}
ll modC(ll n, ll k, ll m) {
  return modFact(n, m) * modInv(modFact(k, m) * modFact(n - k, m) % m, m) % m;
}
int solve(vector<int> as) {
  bool p = true;
  int n = as.size();
  for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < n - i - 1; j++) {
      as[j] = as[j] + as[j + 1] * (p ? 1 : -1);
      p = !p;
    }
  }
  return as[0];
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  vector<int> as(n);
  for (int i = 0; i < n; i++) {
    cin >> as[i];
  }
  for (int i = 1; i <= 31; i++) {
    vector<int> as(i, 1), diffs(i);
    int n1 = solve(as);
    for (int j = 0; j < i; j++) {
      as[j]++;
      diffs[j] = solve(as) - n1;
      as[j]--;
    }
    prints(i / 4, diffs);
  }
  int num = n / 4;
  vector<int> v1, v2, v3, v4;
  for (int i = 0; i < num; i++) {
    int mc = modC(2 * num - 1, i, M);
    v1.push_back(mc);
    v1.push_back(-mc);
  }
  for (int i = 0; i < num; i++) {
    int mc2 = modC(2 * num, i, M);
    v2.push_back(mc2);
    v2.push_back(0);
    v3.push_back(mc2);
    v3.push_back(mc2);
  }
  int mc2 = modC(2 * num, num, M);
  v2.push_back(mc2);
  v3.push_back(mc2);
  {
    vector<int> vv(v1.rbegin(), v1.rend());
    v1.insert(v1.end(), vv.begin(), vv.end());
  }
  for (int i = v1.size() / 2; i < v1.size(); i++) {
    v1[i] *= -1;
  }
  {
    vector<int> vv(v2.rbegin() + 1, v2.rend());
    v2.insert(v2.end(), vv.begin(), vv.end());
  }
  {
    vector<int> vv(v3.rbegin(), v3.rend());
    v3.insert(v3.end(), vv.begin(), vv.end());
  }
  v4 = v3;
  for (uint i = 0; i < v4.size(); i++) {
    if (i & 1) {
      v4[i] *= 2;
    } else if (i) {
      v4[i] -= v3[i - 2];
    }
  }
  v4.push_back(-v4[0]);
  prints(1);
  prints(num, v1);
  prints(num, v2);
  prints(num, v3);
  prints(num, v4);
  int r = n % 4;
  auto& vvv = (r == 0 ? v1 : r == 1 ? v2 : r == 2 ? v3 : v4);
  ll ans = 0;
  for (int i = 0; i < n; i++) {
    ans = (ans + 1ll * vvv[i] * as[i] + M) % M;
  }
  cout << ans << '\n';
  return 0;
}
