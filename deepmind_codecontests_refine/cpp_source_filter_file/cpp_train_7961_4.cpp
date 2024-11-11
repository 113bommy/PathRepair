#include <bits/stdc++.h>
using namespace std;
long long A;
vector<long long> divis;
vector<pair<long long, vector<long long> > > pri_ref;
map<long long, vector<long long> > primes;
map<long long, vector<long long> >::iterator it;
long long dp[7007][1001];
void get_divisors() {
  for (long long i = 1; i * i <= A; ++i)
    if (A % i == 0) {
      divis.push_back(i);
      if (i != A / i) divis.push_back(A / i);
    }
  sort(divis.begin(), divis.end());
}
bool is_prime(long long x) {
  if (x == 0 || x == 1) return false;
  for (long long i = 2; i * i <= x; ++i)
    if (x % i == 0) return false;
  return true;
}
long long get_prime_pow(long long x) {
  if (is_prime(x)) return x;
  for (long long i = 2; i * i <= x; ++i)
    if (x % i == 0) {
      while (x % i == 0) x /= i;
      if (x == 1)
        return i;
      else
        return -1;
    }
  return -1;
}
void get_good_primes() {
  for (long long i = 0; i < (long long)divis.size(); ++i) {
    long long d = divis[i] - 1, prm = get_prime_pow(d);
    if (prm != -1) primes[prm].push_back(d + 1);
  }
}
void get_dp() {
  for (long long i = 0; i <= (long long)pri_ref.size(); ++i) dp[0][i] = 1;
  for (long long i = 1; i < (long long)divis.size(); ++i)
    for (long long j = 1; j <= (long long)pri_ref.size(); ++j) {
      dp[i][j] = dp[i][j - 1];
      for (long long k = 0; k < (long long)pri_ref[j - 1].second.size(); ++k)
        if (divis[i] % (pri_ref[j - 1].second)[k] == 0) {
          long long pos = lower_bound(divis.begin(), divis.end(),
                                      divis[i] / (pri_ref[j - 1].second)[k]) -
                          divis.begin();
          dp[i][j] += dp[pos][j - 1];
        }
    }
}
int main() {
  cin >> A;
  get_divisors();
  get_good_primes();
  for (it = primes.begin(); it != primes.end(); ++it)
    pri_ref.push_back(make_pair(it->first, it->second));
  get_dp();
  cout << dp[divis.size() - 1][primes.size()] << '\n';
  return 0;
}
