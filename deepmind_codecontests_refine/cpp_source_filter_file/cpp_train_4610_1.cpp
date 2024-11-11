#include <bits/stdc++.h>
using namespace std;
template <class T>
void print(T& x) {
  cout << x;
}
template <class T, class U>
void print(pair<T, U>& p) {
  cout << "(";
  print(p.first);
  cout << ", ";
  print(p.second);
  cout << ")";
}
template <class T>
void print(vector<T>& v) {
  cout << "{";
  if (((int)(v).size())) print(v[0]);
  for (int i = 1; i < ((int)(v).size()); i++) cout << ", ", print(v[i]);
  cout << "}\n";
}
const long long MOD = 998244353;
const long long n = 1e6;
long long inv[n];
void precompute_inverse(int n, long long mod) {
  inv[1] = 1;
  for (int i = 2; i <= n; i++)
    inv[i] = (mod - (mod / i) * 1LL * inv[mod % i] % mod) % mod;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int N, M;
  cin >> N >> M;
  vector<int> D(N);
  precompute_inverse(N + M, MOD);
  long long stot = 0;
  for (int i = 0; i < N; i++) {
    cin >> D[i];
    stot += D[i];
  }
  stot %= MOD;
  sort(D.rbegin(), D.rend());
  vector<long long> res(M);
  vector<tuple<int, int, int> > A;
  for (int i = 0; i < M; i++) {
    int a, b;
    cin >> a >> b;
    A.emplace_back(b, a, i);
  }
  sort(A.rbegin(), A.rend());
  long long s = 0, di = 0;
  for (auto [b, a, i] : A) {
    while (di < ((int)(D).size()) && D[di] >= b) {
      (s += D[di++]) %= MOD;
    }
    if (di < a) {
      res[i] = 0;
    } else {
      res[i] = inv[di] * (di - a) % MOD * s % MOD;
      (res[i] += inv[di + 1] * (di - a + 1) % MOD * (stot - s)) %= MOD;
    }
  }
  for (int i = 0; i < M; i++) {
    cout << res[i] << "\n";
  }
}
