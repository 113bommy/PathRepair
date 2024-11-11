#include <bits/stdc++.h>
using namespace std;
bool compare(long long x, long long y) { return x > y; }
long long isprime(long long n) {
  if (n == 1)
    return 0;
  else if (n == 2)
    return 1;
  else {
    for (long long i = 2; i <= sqrt(n); i++) {
      if (n % i == 0) return 0;
    }
    return 1;
  }
}
vector<long long> get_prime_factors_less_than(long long n) {
  vector<long long> factor;
  vector<long long> prime(n, 1);
  prime[0] = 0, prime[1] = 0;
  for (long long i = 2; i <= n; i++) {
    if (prime[i] == 1) {
      for (long long j = i * i; j <= n; j = j + i) prime[j] = 0;
      factor.push_back(i);
    }
  }
  return factor;
}
vector<long long> retain_index(long long arr[], long long n) {
  vector<pair<long long, long long> > vp;
  for (long long i = 0; i < n; ++i) {
    vp.push_back(make_pair(arr[i], i));
  }
  sort(vp.begin(), vp.end());
  vector<long long> retain;
  for (long long i = 0; i < vp.size(); i++) {
    long long a = vp[i].second;
    retain.push_back(a);
  }
  return retain;
}
long long power(long long x, long long y) {
  if (y == 0) return 1;
  long long a = power(x, y / 2);
  if (y % 2 == 0)
    return a * a;
  else
    return x * a * a;
}
int main() {
  {
    ios ::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
  };
  long long n, d;
  cin >> n >> d;
  long long array[n];
  for (long long i = 0; i < n; i++) cin >> array[i];
  sort(array, array + n);
  long long s = 0;
  long long i = 0, m;
  cin >> m;
  for (i = 0; i < n; i++) {
    if (i > m - 1)
      break;
    else
      s = s + array[i];
  }
  if (i != n)
    cout << s << endl;
  else
    cout << s - d * (m - i) << endl;
}
