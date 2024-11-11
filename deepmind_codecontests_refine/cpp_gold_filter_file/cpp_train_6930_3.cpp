#include <bits/stdc++.h>
using namespace std;
int maxim = 1000001;
vector<int> primes;
void seive() {
  vector<bool> isprime(maxim + 1, true);
  for (int i = 2; i * i <= maxim; i++) {
    if (isprime[i]) {
      for (int j = 2 * i; j <= maxim; j += i) {
        isprime[j] = false;
      }
    }
  }
  for (int i = 2; i <= maxim; i++) {
    if (isprime[i]) {
      primes.push_back(i);
    }
  }
}
int main() {
  int n, ans = 0;
  cin >> n;
  seive();
  for (int i = 1; i <= 1000; i++) {
    int z = n * i + 1;
    if (!binary_search(primes.begin(), primes.end(), z)) {
      ans = i;
      break;
    }
  }
  cout << ans;
  return 0;
}
