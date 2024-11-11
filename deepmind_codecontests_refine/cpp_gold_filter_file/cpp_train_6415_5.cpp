#include <bits/stdc++.h>
using namespace std;
const int N = (int)1e6;
const int MOD = (int)1e9 + 7;
const int inf = (int)5e8;
const long long infll = (long long)1e17;
bool isPrime(int n) {
  for (int i = 2; i * i <= n; ++i) {
    if (n % i == 0) {
      return false;
    }
  }
  return true;
}
bool prime[N];
void sieve() {
  memset(prime, true, sizeof prime);
  for (int i = 2; i < N; ++i) {
    if (prime[i]) {
      if (i * 1ll * i < N) {
        for (int j = i * i; j < N; j += i) {
          prime[j] = false;
        }
      }
    }
  }
}
map<int, int> dp;
vector<int> use = {4, 6, 9};
int calc(int n) {
  if (n == 0) return 0;
  if (dp.count(n)) return dp[n];
  int ans = -1;
  for (auto i : use) {
    if (i > n) {
      break;
    }
    int add = calc(n % i);
    if (add != -1) {
      ans = max(ans, n / i + add);
    }
  }
  return dp[n] = ans;
}
void solve() {
  int n;
  scanf("%d", &n);
  if (n % 4 == 0) {
    printf("%d\n", n / 4);
    return;
  }
  if (n % 4 == 1) {
    if (n >= 9) {
      printf("%d\n", n / 4 - 1);
      return;
    }
  }
  if (n % 4 == 2) {
    if (n >= 6) {
      printf("%d\n", n / 4);
      return;
    }
  }
  if (n % 4 == 3) {
    if (n >= 15) {
      printf("%d\n", 2 + (n - 15) / 4);
      return;
    }
  }
  printf("-1\n");
}
int main() {
  int t = 1;
  sieve();
  scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}
