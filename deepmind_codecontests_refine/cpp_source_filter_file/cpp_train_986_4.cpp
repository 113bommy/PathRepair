#include <bits/stdc++.h>
using namespace std;
bool sieve[1000100];
vector<long long> primes;
long long v[1010];
long long dp[1000100];
long long sum;
void mountSieve() {
  for (int i = 2; i * i < 1000100; i++) {
    if (!sieve[i]) {
      int x = i * i;
      while (x < 1000100) {
        sieve[x] = true;
        x += i;
      }
    }
  }
  for (int i = 2; i < 1000100; i++) {
    if (!sieve[i]) {
      primes.push_back(i);
    }
  }
}
int main() {
  mountSieve();
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &v[i]);
    sum += v[i];
  }
  sum--;
  for (int i = 0; primes[i] <= sum; i++) {
    long long x = primes[i];
    while (x <= sum) {
      dp[primes[i]] += sum / x;
      x *= primes[i];
    }
  }
  for (int j = 1; j <= n; j++) {
    sum = v[j] - 1;
    for (int i = 0; primes[i] <= sum; i++) {
      long long x = primes[i];
      while (x <= sum) {
        dp[primes[i]] -= sum / x;
        x *= primes[i];
      }
    }
  }
  sum = 0;
  for (int i = 1; i < n; i++) {
    sum += v[i];
    long long x = sum;
    for (int j = 0; primes[j] <= x; j++) {
      while (x % primes[j] == 0) {
        dp[primes[j]]--;
        x /= primes[j];
      }
    }
  }
  long long ans = 1;
  for (int i = 1; i <= 10; i++) {
    while (dp[i]--) {
      ans *= i;
      if (ans >= 1000000007) ans %= 1000000007;
    }
  }
  cout << ans << endl;
  return 0;
}
