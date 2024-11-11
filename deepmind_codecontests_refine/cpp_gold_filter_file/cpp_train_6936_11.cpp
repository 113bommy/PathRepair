#include <bits/stdc++.h>
using namespace std;
int prime[1000010], sn[1000010];
map<int, int> factors[1000011];
long long fact[2000100], mt[1000010];
long long moduloexp(long long a, long long b) {
  long long res = 1;
  while (b) {
    if (b & 1) res = (1LL * res * a) % 1000000007;
    b /= 2;
    a = (1LL * a * a) % 1000000007;
  }
  return res;
}
long long comb(long long n, long long r) {
  if (n < r) return 0;
  return (1LL * fact[n] *
          moduloexp((1LL * fact[n - r] * fact[r]) % 1000000007,
                    1000000007 - 2)) %
         1000000007;
}
void init() {
  fact[0] = 1;
  for (int i = 1; i < 2000010; i++) fact[i] = (fact[i - 1] * i) % 1000000007;
}
void sieve() {
  for (int i = 2; i < 1000010; i++) {
    if (!prime[i]) {
      for (int j = 2 * i; j < 1000010; j += i) {
        if (!prime[j]) {
          prime[j] = 1;
          sn[j] = i;
        }
      }
    }
  }
  for (int i = 2; i < 1000010; i++) {
    if (!sn[i]) sn[i] = i;
  }
}
void factorise(int x) {
  int cur = sn[x];
  int n = x;
  while (x > 1) {
    while (sn[x] == cur) {
      factors[n][cur]++;
      x = x / sn[x];
    }
    cur = sn[x];
  }
}
int main() {
  ios::sync_with_stdio(false);
  sieve();
  init();
  for (int i = 1; i < 1000010; i++) {
    factorise(i);
  }
  long long mult = 0;
  int q;
  cin >> q;
  while (q--) {
    int x, y;
    cin >> x >> y;
    long long ans = 1;
    for (auto val : factors[x]) {
      ans = (ans * comb(val.second + y - 1, val.second)) % 1000000007;
    }
    cout << (ans * moduloexp(2, y - 1)) % 1000000007 << '\n';
  }
}
