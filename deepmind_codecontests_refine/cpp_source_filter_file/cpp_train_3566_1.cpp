#include <bits/stdc++.h>
using namespace std;
const int M = 1e9 + 7;
int ll_max = 1e6;
vector<long long int> fact;
void factorial(long long int n) {
  fact[0] = 1;
  for (long long int i = 1; i <= n; i++) {
    fact[i] = i * fact[i - 1];
    fact[i] %= M;
  }
}
long long int binpow(long long int val, long long int deg) {
  if (!deg) return 1 % M;
  if (deg & 1) return binpow(val, deg - 1) * val % M;
  long long int res = binpow(val, deg >> 1);
  return (res * res) % M;
}
long long int combination(long long int n, long long int i) {
  long long int res = fact[n];
  long long int div = fact[n - i] * fact[i];
  div %= M;
  div = binpow(div, M - 2);
  return (res * div) % M;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  long long int n, m, i;
  long long int j, t, x, y, z, k, d;
  cin >> t;
  while (t--) {
    cin >> n;
    long long int a[n];
    long long int sum = 0;
    for (long long int i = 0; i < n; i++) {
      cin >> a[i];
      if (i % 2 == 0) sum += a[i];
    }
    vector<long long int> t1, t2;
    for (i = 0; i < n; i += 2) {
      if (i + 1 < n) t1.push_back(a[i + 1] - a[i]);
    }
    for (i = 1; i < n; i += 2) {
      if (i + 1 < n) t2.push_back(a[i + 1] - a[i]);
    }
    long long int max = 0;
    long long int max_so_far = 0, max_ending_here = 0;
    for (i = 0; i < t1.size(); i++) {
      max_ending_here = max_ending_here + t1[i];
      if (max_so_far < max_ending_here) max_so_far = max_ending_here;
      if (max_ending_here < 0) max_ending_here = 0;
    }
    max = max_so_far;
    max_so_far = 0, max_ending_here = 0;
    for (i = 0; i < t2.size(); i++) {
      max_ending_here = max_ending_here + t2[i];
      if (max_so_far < max_ending_here) max_so_far = max_ending_here;
      if (max_ending_here < 0) max_ending_here = 0;
    }
    if (max < max_so_far) max = max_so_far;
    cout << max + sum << '\n';
  }
  return 0;
}
