#include <bits/stdc++.h>
using namespace std;
vector<int> mass[1000500];
long long masss[1000050];
int ans[1000050];
int summ = 0;
long long const MOD = 998244353;
long long binpow(long long a, long long n) {
  if (n == 0) return 1;
  if (n % 2 == 1)
    return ((binpow(a, n - 1) * a) % MOD);
  else {
    long long b = ((binpow(a, n / 2)) % MOD);
    return ((b * b) % MOD);
  }
}
long long gcd(long long a, long long b) {
  if (b == 0)
    return a;
  else
    return gcd(b, a % b);
}
int main() {
  long long a, b, c;
  cin >> a;
  for (int qq = 0; qq < a; qq++) {
    cin >> masss[qq];
    for (int q = 0; q < masss[qq]; q++) {
      cin >> c;
      mass[qq].push_back(c);
      ans[c]++;
    }
  }
  long long x = 0;
  long long y = 1;
  for (int q = 0; q < a; q++) {
    for (int w = 0; w < mass[q].size(); w++) {
      long long d = gcd(y, mass[q].size());
      x = (x * (mass[q].size() / d) + (y / d) * ans[mass[q][w]]) % MOD;
      y = (y * mass[q].size() / d) % MOD;
    }
  }
  y = (((y * a) % MOD) * a) % MOD;
  cout << (binpow(y * a * a, 998244351) * x) % MOD;
}
