#include <bits/stdc++.h>
using namespace std;
long long int power(long long int x, long long int p) {
  if (p == 0) return 1;
  if (p == 1) return x % 1000000007;
  long long int ans = power(x, p / 2);
  ans = (ans * ans) % 1000000007;
  if (p % 2 == 1) ans = (ans * x) % 1000000007;
  return ans;
}
int main() {
  long long int x, n;
  cin >> x >> n;
  vector<long long int> prime;
  for (long long int i = 2; i * i <= x; i++) {
    if (x % i == 0) {
      prime.push_back(i);
      while (x % i == 0) x /= i;
    }
  }
  if (x > 1) prime.push_back(x);
  long long int ans = 1;
  for (int i = 0; i < prime.size(); i++) {
    long long int t = n, p = 0;
    while (t > 0) {
      p += t / prime[i];
      t /= prime[i];
    }
    ans = (ans * (power(prime[i], p))) % 1000000007;
  }
  cout << ans;
}
