#include <bits/stdc++.h>
using namespace std;
vector<long long int> segmented_sieve(long long L, long long R) {
  long long lim = sqrt(R);
  vector<bool> mark(lim + 1, false);
  vector<long long> primes;
  for (long long i = 2; i <= lim; ++i) {
    if (!mark[i]) {
      primes.emplace_back(i);
      for (long long j = i * i; j <= lim; j += i) mark[j] = true;
    }
  }
  vector<bool> isPrime(R - L + 1, true);
  vector<long long> prime;
  for (long long i : primes) {
    for (long long j = max(i * i, (L + i - 1) / i * i); j <= R; j += i) {
      isPrime[j - L] = false;
    }
    if (L == 1) isPrime[0] = false;
  }
  for (long long i = 0; i < int((isPrime).size()); i++) {
    if (isPrime[i]) {
      prime.push_back(L + i);
    }
  }
  return prime;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n, k;
  cin >> n >> k;
  map<int, pair<int, int>> m;
  vector<long long int> v(n, 0);
  long long int sum_l = 0, sum_r = 0, sum_coins = 0;
  for (long long i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    v[i] = x - y;
    sum_l += x;
    sum_r += y;
  }
  if (sum_r > k) {
    cout << "-1";
  } else if (k >= sum_l) {
    cout << "0";
  } else {
    long long int sum = 0, cnt = 0;
    bool check = true;
    sort(v.begin(), v.end(), greater<int>());
    for (long long i = 0; i < int((v).size()); i++) {
      ++cnt;
      sum += v[i];
      if (sum >= sum_l - k) {
        check = false;
        break;
      }
    }
    if (check) {
      cout << "-1";
    } else {
      cout << cnt;
    }
  }
}
