#include <bits/stdc++.h>
using namespace std;
bool prime[1000000 + 1];
vector<long> v;
void sieve() {
  memset(prime, true, sizeof(prime));
  for (long p = 2; p * p <= 1000000; p++) {
    if (prime[p] == true) {
      for (long i = p * p; i <= 1000000; i += p) prime[i] = false;
    }
  }
  for (int i = 0; i <= 1000000; i++)
    if (prime[i]) v.push_back(i);
}
long long gcd(long long a, long long b) {
  if (a == 0) return b;
  return gcd(b % a, a);
}
long long power(int v, int a) {
  long long prod = 1;
  for (int i = 0; i < a; i++) prod *= v;
  return prod;
}
double dist(long long a, long long b, long long c, long long d) {
  double t = (a - c) * (a - c);
  double p = (b - d) * (b - d);
  return sqrt(t + p);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int T = 1;
  while (T--) {
    int n;
    cin >> n;
    long long a[n];
    unsigned long long sum = 0;
    for (int i = 0; i < n; i++) cin >> a[i];
    int cnt = 0;
    for (int i = 0; i < n; i++) {
      if (a[i + 1] == a[i]) {
        cnt = 1;
        while (a[i] == a[i + 1]) {
          i++;
          cnt++;
        }
        sum += cnt * (cnt - 1) / 2;
      }
    }
    cout << n + sum;
  }
  cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
}
