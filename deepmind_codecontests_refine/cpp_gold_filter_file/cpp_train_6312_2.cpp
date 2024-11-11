#include <bits/stdc++.h>
using namespace std;
bool pr[100000007];
void sieve() {
  pr[0] = 1;
  pr[1] = 1;
  for (int i = 2; i < sqrt(100000007); i++) {
    for (int j = 2 * i; j <= 100000007; j += i) {
      pr[j] = 1;
    }
  }
}
long long fpow(long long x, long long y) {
  long long res = 1;
  while (y) {
    if (y & 1) res = res * x;
    res %= 1000000007;
    y = y >> 1;
    x = x * x;
    x %= 1000000007;
  }
  return res;
}
unsigned long long lopow(long long x, long long y) {
  unsigned long long res = 1ULL;
  while (y) {
    if (y & 1) res *= (unsigned long long)x;
    y >>= 1;
    x *= x;
  }
  return res;
}
vector<long long> prime;
void pf(long long n) {
  while (n % 2 == 0) {
    prime.push_back(2);
    n = n / 2;
  }
  for (int i = 3; i * i <= (n); i = i + 2) {
    while (n % i == 0) {
      prime.push_back(i);
      n = n / i;
    }
  }
  if (n > 2) prime.push_back(n);
}
int mobius(long long n) {
  prime.clear();
  pf(n);
  int c[1000000] = {0};
  for (int i = 0; i < prime.size(); i++) {
    c[prime[i]]++;
  }
  for (int i = 1; i < 1000000; i++) {
    if (c[i] >= 2) return 0;
  }
  if (prime.size() & 1) return -1;
  return 1;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long x, y;
  cin >> x >> y;
  if (y % x != 0) {
    cout << 0;
    return 0;
  }
  long long n = y / x;
  vector<int> g;
  for (int i = 1; i * i <= n; i++) {
    if (n % i == 0) {
      g.push_back(i);
      if (n / i != i) g.push_back(n / i);
    }
  }
  sort(g.begin(), g.end());
  long long ans = 0;
  for (int i = 0; i < g.size(); i++) {
    ans = (ans + (mobius(n / g[i]) * fpow(2, g[i] - 1)) % 1000000007) %
          1000000007;
    ans = (ans + 1000000007) % 1000000007;
  }
  cout << ans << "\n";
}
