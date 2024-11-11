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
  long long n, p;
  cin >> p >> n;
  vector<pair<long long, long long> > v;
  for (long long i = 0; i < n; i++) {
    long long a, b;
    cin >> a >> b;
    v.push_back(make_pair(a, b));
  }
  sort(v.begin(), v.end());
  long long c = 0;
  for (long long i = 0; i < n; i++) {
    if (v[i].first > p) {
      c++;
    }
    p += v[i].second;
  }
  if (c > 0)
    cout << "NO";
  else
    cout << "YES";
  return 0;
}
