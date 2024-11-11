#include <bits/stdc++.h>
#pragma GCC optimize(2)
using namespace std;
using LL = long long;
using PII = pair<int, int>;
const int MXN = 5005;
int primeFactorization[MXN][MXN], cnt[MXN];
void preProcess() {
  memset(primeFactorization, 0, sizeof(primeFactorization));
  for (int i = 1; i < MXN; ++i) {
    for (int j = 0; j < MXN; ++j) {
      primeFactorization[i][j] = primeFactorization[i - 1][j];
    }
    int tmp = i;
    for (int j = 2; j * j <= tmp; ++j) {
      while (tmp % j == 0) {
        ++primeFactorization[i][j];
        tmp /= j;
      }
    }
    if (tmp != 1) {
      ++primeFactorization[i][tmp];
    }
  }
}
void sol(int n) {
  vector<int> bestPrimes(MXN, 1);
  LL ans = 0, cur = 0;
  for (int i = 1; i < MXN; ++i) {
    if (cnt[i] == 0) {
      bestPrimes[i] = 1;
      continue;
    }
    for (int j = 1; j < MXN; ++j) {
      ans += 1LL * primeFactorization[i][j] * cnt[i];
      if (primeFactorization[i][j] != 0) {
        bestPrimes[i] = j;
      }
    }
  }
  cur = ans;
  while (*max_element(bestPrimes.begin(), bestPrimes.end()) > 1) {
    vector<int> frequency(MXN, 0);
    for (int i = 0; i < MXN; ++i) {
      frequency[bestPrimes[i]] += cnt[i];
    }
    int bestPrime =
        max_element(frequency.begin(), frequency.end()) - frequency.begin();
    int bestCount = frequency[bestPrime];
    if (bestCount * 2 - n <= 0 || bestPrime == 1) {
      break;
    }
    cur += (n - bestCount) - bestCount;
    ans = min(ans, cur);
    for (int i = 0; i < MXN; ++i) {
      if (bestPrimes[i] != bestPrime) {
        bestPrimes[i] = 1;
      }
      if (bestPrimes[i] == 1) {
        continue;
      }
      --primeFactorization[i][bestPrimes[i]];
      while (bestPrimes[i] > 1 && primeFactorization[i][bestPrimes[i]] == 0) {
        --bestPrimes[i];
      }
    }
  }
  cout << ans << '\n';
}
int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);
  ;
  int n;
  vector<int> a;
  preProcess();
  cin >> n;
  a.resize(n + 5);
  for (int i = 0, x; i < n; ++i) {
    cin >> x;
    ++cnt[x];
  }
  sol(n);
}
