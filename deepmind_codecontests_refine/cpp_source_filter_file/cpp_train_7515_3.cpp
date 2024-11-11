#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
const long long LLINF = 1e18 + 7;
long long best = LLINF;
int n;
int tab[1000009];
void check(int p) {
  long long s = 0, res = 0;
  for (int i = 0; i < n; i++) {
    s = (s + tab[i]) % p;
    res += min(s, p - s);
  }
  best = min(best, res);
}
set<long long> primes;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ;
  cin >> n;
  long long summ = 0;
  for (int i = 0; i < n; i++) {
    cin >> tab[i];
    summ += tab[i];
  }
  if (summ == 1) {
    cout << -1;
    return 0;
  }
  for (long long i = 2; i * i <= summ; i++) {
    if (summ % i == 0) {
      primes.insert(i);
      summ /= i;
      i--;
    }
  }
  primes.insert(summ);
  for (long long p : primes) {
    check(p);
  }
  cout << best;
}
