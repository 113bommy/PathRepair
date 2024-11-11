#include <bits/stdc++.h>
using namespace std;
const long long M = 1e9 + 7;
const long long INF = 1e9;
inline long long pwr(long long base, long long n, long long m) {
  long long ans = 1;
  while (n > 0) {
    if (n % 2 == 1) ans = (ans * base) % m;
    base = (base * base) % m;
    n /= 2;
  }
  return ans;
}
long long v, ncr[15005][510];
map<int, long long> cnt;
bool prime[100005];
vector<int> primes;
int n;
void sieve() {
  memset(prime, true, sizeof(prime));
  for (int i = 2; i < 100001; i++) {
    if (prime[i]) {
      primes.push_back(i);
      int j = i * 2;
      while (j <= 100000) {
        prime[j] = false;
        j += i;
      }
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ncr[0][0] = 1;
  sieve();
  cin >> n;
  for (int i = 1; i < 15002; i++) {
    ncr[i][0] = 1;
    for (int j = 1; j < min(i + 1, n + 1); j++) {
      ncr[i][j] = (ncr[i - 1][j] + ncr[i - 1][j - 1]) % M;
    }
  }
  for (int i = 0; i < n; i++) {
    cin >> v;
    for (auto j : primes) {
      if (j > v) break;
      while (v % j == 0) {
        cnt[j]++;
        v /= j;
      }
    }
    if (v > 1) cnt[v]++;
  }
  long long ans = 1;
  for (auto i : cnt) {
    ans = (ans * ncr[n + i.second - 1][n - 1]) % M;
  }
  cout << ans;
  return 0;
}
