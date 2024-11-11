#include <bits/stdc++.h>
using namespace std;
long long fact(long long n) {
  long long f = 1;
  for (long long i = 2; i <= n; i++) f *= i;
  return f;
}
long long ncr(long long n, long long r) {
  return fact(n) / (fact(r) * fact(n - r));
}
long long isPrime(long long n) {
  if (n <= 1) return 0;
  if (n <= 3) return 1;
  if (n % 2 == 0 || n % 3 == 0) return 0;
  for (long long i = 5; i * i <= n; i = i + 6)
    if (n % i == 0 || n % (i + 2) == 0) return 0;
  return 1;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  srand(time(NULL));
  long long t;
  cin >> t;
  while (t > 0) {
    long long n;
    cin >> n;
    vector<long long> v;
    for (long long i = 0; i < n; i++) {
      long long a;
      cin >> a;
      v.push_back(a);
    }
    long long c = 1;
    for (long long i = 0; i < n - 1; i++) {
      if (abs(v[i] - v[i + 1]) >= 2) {
        cout << "YES" << endl;
        cout << i + 1 << " " << i + 2 << endl;
        c = 0;
        break;
      }
    }
    if (c == 1) cout << "NO" << endl;
    t--;
  }
  return 0;
}
