#include <bits/stdc++.h>
using namespace std;
long long mod = 1e9 + 7;
pair<long long, long long> fib(long long N) {
  if (N == 1) {
    return {1, 1};
  }
  if (N % 2) {
    pair<long long, long long> eff = fib(N - 1);
    return {eff.second, (eff.first + eff.second) % mod};
  } else {
    pair<long long, long long> eff = fib(N / 2);
    long long a = eff.second, b = eff.first;
    long long bg = (a * a + b * b) % mod;
    long long sm = (a * b + b * (a - b + mod)) % mod;
    return {sm, bg};
  }
}
long long fibb(long long N) {
  if (N == 1) return 1;
  return fib(N - 1).second;
}
bool chk(long long u, long long L, long long R, long long K) {
  if (u == 0) {
    return 0;
  }
  return (R / u) - ((L - 1) / u) >= K;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long L, R, K;
  cin >> mod >> L >> R >> K;
  long long ans = 0;
  for (long long i = 1; i * i <= R; i++) {
    if (chk(i, L, R, K)) {
      ans = max(ans, i);
    }
  }
  for (long long bs = 1; bs * bs <= R; bs++) {
    if (chk(R / bs, L, R, K)) {
      ans = max(ans, R / bs);
    }
  }
  for (long long bs = 1; bs * bs <= L - 1; bs++) {
    if (chk((L - 1) / bs, L, R, K)) {
      ans = max(ans, (L - 1) / bs);
    }
    if ((chk(((L - 1) / bs) - 1, L, R, K))) {
      ans = max(ans, ((L - 1) / bs) - 1);
    }
  }
  cout << fibb(1e12 + 7);
  return 0;
}
