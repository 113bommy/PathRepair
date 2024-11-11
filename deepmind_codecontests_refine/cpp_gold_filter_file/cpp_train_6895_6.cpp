#include <bits/stdc++.h>
using namespace std;
const int maxn = 60;
const int mod = 998244353;
long long frac[maxn];
long long inv_frac[maxn];
long long pow(long long a, long long b, int mod) {
  long long ans = 1, base = a;
  while (b) {
    if (b & 1) ans = (ans * base) % mod;
    base = (base * base) % mod;
    b >>= 1;
  }
  return ans;
}
long long factor[maxn];
int fac_cnt = 0;
long long D;
void init() {
  inv_frac[0] = frac[0] = 1;
  for (int i = 1; i < maxn; i++) {
    frac[i] = (frac[i - 1] * i) % mod;
    inv_frac[i] = pow(frac[i], mod - 2, mod);
  }
  for (long long i = 2; i * i <= D; i++) {
    while (D % i == 0) {
      if (factor[fac_cnt] != i) factor[++fac_cnt] = i;
      D /= i;
    }
  }
  if (D > 1) factor[++fac_cnt] = D;
}
vector<pair<long long, int> > divide(long long n) {
  vector<pair<long long, int> > vec;
  for (long long i = 1; i <= fac_cnt && factor[i] * factor[i] <= n; i++) {
    while (n % factor[i] == 0) {
      if (!vec.empty() && vec.back().first == factor[i])
        vec.back().second++;
      else
        vec.emplace_back(factor[i], 1);
      n /= factor[i];
    }
  }
  if (n != 1) vec.emplace_back(n, 1);
  return vec;
}
long long calc(long long n) {
  auto vec = divide(n);
  int sum = 0;
  for (auto p : vec) sum += p.second;
  long long ans = frac[sum];
  for (auto p : vec) ans = (ans * inv_frac[p.second]) % mod;
  return ans;
}
long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a % b); }
int main() {
  ios_base::sync_with_stdio(false);
  init();
  int Q;
  cin >> D >> Q;
  init();
  for (int i = 1; i <= Q; i++) {
    long long u, v;
    cin >> u >> v;
    if (u < v) swap(u, v);
    long long t = gcd(u, v);
    long long ans = calc(u / t) * calc(v / t) % mod;
    cout << ans << "\n";
  }
}
