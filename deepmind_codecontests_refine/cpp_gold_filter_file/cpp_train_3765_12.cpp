#include <bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
inline long long int rand(long long int x, long long int y) {
  ++y;
  return (rng() % (y - x)) + x;
}
string to_string(char c) {
  string second(1, c);
  return second;
}
string to_string(bool b) { return (b ? "true" : "false"); }
template <typename A, typename B>
string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}
template <typename A>
string to_string(A v) {
  bool first = true;
  string res = "{";
  for (const auto &x : v) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(x);
  }
  res += "}";
  return res;
}
void degug_out() { cerr << endl; }
template <typename Head, typename... Tail>
void degug_out(Head H, Tail... T) {
  cerr << " " << to_string(H);
  degug_out(T...);
}
inline long long int gcd(long long int a, long long int b) {
  if (a > b) swap(a, b);
  if (a == 0) return b;
  return gcd(b % a, a);
}
long long int n, A[(300006)];
long long int hashs[(300006)], ans;
long long int mp[(300006)];
const long long int MOD = 1009999909;
long long int qexp(long long int x, long long int e) {
  if (e == 0) return 1;
  long long int half = qexp(x, e / 2ll);
  half *= half;
  half %= MOD;
  if (e % 2ll) half *= x;
  half %= MOD;
  return half;
}
vector<long long int> ones;
long long int base = 333101;
void solve(long long int pos) {
  long long int len = 1;
  while (pos < n && A[pos + 1] != 1) {
    len = max(len, A[++pos]);
    ans += (mp[len] == ((hashs[pos] - hashs[pos - len] + MOD) % MOD));
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  for (long long int i = 1; i < (long long int)n + 1; ++i) cin >> A[i];
  for (long long int i = 1; i < (long long int)n + 1; ++i)
    hashs[i] = (qexp(base, A[i]) + hashs[i - 1]) % MOD;
  long long int hash = 0;
  for (long long int i = 1; i < (long long int)n + 1; ++i)
    hash += qexp(base, i), hash %= MOD, mp[i] = hash;
  for (long long int times = 0; times < 2; times++) {
    for (long long int i = 1; i < (long long int)n + 1; ++i)
      if (A[i] == 1) solve(i);
    reverse(A + 1, A + n + 1);
    if (0) cerr << "reversed\n";
    for (long long int i = 1; i < (long long int)n + 1; ++i)
      hashs[i] = (qexp(base, A[i]) + hashs[i - 1]) % MOD;
  }
  ans += count(A + 1, A + n + 1, 1);
  cout << ans << '\n';
}
