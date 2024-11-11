#include <bits/stdc++.h>
using namespace std;
vector<int> primes;
bool sums[1003];
int n, k;
bool pr[1003];
void sieve() {
  pr[1] = pr[0] = 1;
  for (int i = 2; i <= n; i++)
    if (!pr[i]) {
      for (int j = i + i; j <= n; j += i) pr[j] = 1;
      primes.push_back(i);
    }
  return;
}
int main() {
  cin >> n >> k;
  sieve();
  for (int i = 1; i < primes.size(); i++)
    if (primes[i] + primes[i - 1] <= n) sums[primes[i] + primes[i - 1]] = 1;
  for (int i = 2; i <= n; ++i)
    if (sums[i - 1] && !pr[i]) k--;
  cout << (k <= 0 ? "YES" : "NO");
}
