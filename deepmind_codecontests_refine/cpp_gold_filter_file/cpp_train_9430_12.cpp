#include <bits/stdc++.h>
double pi = acos(-1);
const long long mod = 1000000007;
using namespace std;
void optimizeIO() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}
const long long N = 1000005;
long long fact[N], invfact[N];
long long power(long long x, long long y) {
  if (y <= 0) return 1LL;
  long long z = power(x, y / 2);
  if (y % 2) return (((z * z) % mod) * x) % mod;
  return (z * z) % mod;
}
void pre() {
  fact[0] = invfact[0] = invfact[1] = fact[1] = 1;
  for (int i = 2; i < N; i++) fact[i] = (i * fact[i - 1]) % mod;
  for (int i = 2; i < N; i++)
    invfact[i] = (invfact[i - 1] * power(i, mod - 2)) % mod;
}
long long nCr(long long n, long long k) {
  if (k < 0 || k > n) return 0;
  return (((fact[n] * invfact[n - k]) % mod) * invfact[k]) % mod;
}
const long long N1 = 1e6 + 1;
vector<long long> isprime(N1, 1), prime;
void seive() {
  for (int i = 2; i < sqrt(N1) + 1; i++) {
    if (isprime[i]) {
      for (long long j = i * i; j < N1; j += i) isprime[j] = 0;
      prime.push_back(i);
    }
  }
  for (int i = sqrt(N1) + 1; i < N1; i++)
    if (isprime[i]) prime.push_back(i);
}
struct dsu {
  vector<long long> par, rank;
  dsu(long long n) : par(n + 1), rank(n + 1) {
    for (long long i = 0; i <= n; i++) {
      par[i] = i;
      rank[i] = 1;
    }
  }
  long long root(long long a) {
    if (a == par[a]) return a;
    return par[a] = root(par[a]);
  }
  void merge(long long a, long long b) {
    a = root(a);
    b = root(b);
    if (a == b) return;
    if (rank[a] > rank[b]) swap(a, b);
    par[b] = a;
  }
  set<long long> parent(long long n) {
    set<long long> second;
    for (long long i = 1; i <= n; i++) {
      second.insert(root(i));
    }
    return second;
  }
};
void solve() {
  vector<int> count(3, 0);
  for (int j = 0; j < 3; j++) {
    string line;
    getline(cin, line);
    for (auto i : line)
      if (i == 'a' || i == 'e' || i == 'i' || i == 'o' || i == 'u') count[j]++;
  }
  if (count[0] == 5 && count[1] == 7 && count[2] == 5)
    cout << "YES";
  else
    cout << "NO";
}
int main() {
  optimizeIO();
  { solve(); }
}
