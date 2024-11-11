#include <bits/stdc++.h>
using namespace std;
template <typename T>
void _do(vector<T> x) {
  for (auto i : x) cerr << i << ' ';
  cerr << "\n";
}
template <typename T>
void _do(set<T> x) {
  for (auto i : x) cerr << i << ' ';
  cerr << "\n";
}
template <typename T>
void _do(unordered_set<T> x) {
  for (auto i : x) cerr << i << ' ';
  cerr << "\n";
}
template <typename T>
void _do(T&& x) {
  cerr << x << endl;
}
template <typename T, typename... S>
void _do(T&& x, S&&... y) {
  cerr << x << ", ";
  _do(y...);
}
template <typename T>
void print(T&& x) {
  cout << x << "\n";
}
template <typename T, typename... S>
void print(T&& x, S&&... y) {
  cout << x << ' ';
  print(y...);
}
void solve() {
  const int M = 1e5 + 1, MOD = 1e9 + 7;
  vector<int> mu(M, -2);
  vector<int> primes;
  mu[1] = 1;
  for (int i = 2; i < M; i++) {
    if (mu[i] == -2) {
      primes.push_back(i);
      mu[i] = -1;
    }
    for (int p : primes) {
      if (1LL * i * p >= M) break;
      if (i % p == 0) {
        mu[i * p] = 0;
        break;
      }
      mu[i * p] = -mu[i];
    }
  }
  vector<int> f(M);
  for (int i = 1; i < M; i++)
    for (int d = 1; i * d < M; d++) f[i * d] = (f[i * d] + mu[d] * i) % MOD;
  int n;
  cin >> n;
  vector<vector<int>> fac(n + 1);
  for (int i = 1; i <= n; i++) {
    int a;
    cin >> a;
    for (int j = 1; 1LL * j * j <= a; j++)
      if (a % j == 0) {
        fac[i].push_back(j);
        if (j * j != a) fac[i].push_back(a / j);
      }
  }
  vector<int> cnt(M);
  int ans = 0;
  for (int T = 1; T <= n; T++) {
    int G = 0;
    vector<int> vec;
    for (int i = 1; i * T <= n; i++) {
      for (int p : fac[i * T])
        if (cnt[p]++ == 0) vec.push_back(p);
    }
    for (int p : vec) G = (G + 1LL * f[p] * cnt[p] % MOD * cnt[p]) % MOD;
    for (int i = 1; i * T <= n; i++) {
      for (int p : fac[i * T]) cnt[p]--;
    }
    ans = (ans + G * f[T]) % MOD;
  }
  if (ans < 0) ans += MOD;
  cout << ans << endl;
}
int main() {
  cin.tie(0), cout.tie(0);
  ios::sync_with_stdio(false);
  solve();
}
