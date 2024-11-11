#include <bits/stdc++.h>
using namespace std;
const long long MOD = 998244353;
long long inv(long long v) {
  long long g = MOD, x = 0, y = 1;
  for (long long r = v; r != 0;) {
    long long q = g / r;
    g %= r;
    swap(g, r);
    x -= q * y;
    swap(x, y);
  }
  assert(g == 1);
  assert(y == MOD || y == -MOD);
  return x < 0 ? x + MOD : x;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int N;
  long long K;
  cin >> N >> K;
  int actual_N = N;
  vector<int> a(N);
  for (int i = 0; i < N; ++i) {
    cin >> a[i];
    if (i > 0 && a[i] == a[i - 1]) actual_N--;
  }
  if (a[0] == a[N - 1]) actual_N--;
  long long diff = N - actual_N;
  long long factor = 1;
  for (int i = 0; i < diff; ++i) {
    factor = (factor * K) % MOD;
  }
  N = actual_N;
  vector<long long> factorial(N + 1, 1), inv_factorial(N + 1, 1);
  vector<long long> pow2(N + 1, 1);
  for (int i = 1; i <= N; ++i) {
    factorial[i] = (factorial[i - 1] * i) % MOD;
    inv_factorial[i] = inv(factorial[i]);
    pow2[i] = (pow2[i - 1] * 2) % MOD;
  }
  auto choose = [&](int n, int r) {
    return factorial[n] * inv_factorial[r] % MOD * inv_factorial[n - r] % MOD;
  };
  long long powK = 1;
  long long answer = 0;
  long long inv_2 = inv(2);
  for (int i = 0; i < N; ++i) {
    long long ways = choose(N, i) * powK;
    long long remaining = pow2[N - i];
    if ((N - i) % 2 == 0) {
      remaining = (remaining - choose(N - i, (N - i) / 2)) % MOD;
      if (remaining < MOD) remaining += MOD;
    }
    remaining = remaining * inv(2) % MOD;
    ways = (ways * remaining) % MOD;
    answer = (answer + ways) % MOD;
    powK = (powK * (K - 2)) % MOD;
  }
  cout << (factor * answer) % MOD << endl;
  return 0;
}
