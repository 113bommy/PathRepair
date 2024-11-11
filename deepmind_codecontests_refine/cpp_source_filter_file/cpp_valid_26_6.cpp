#include <bits/stdc++.h>
using namespace std;
long long power(long long a, long long n, long long md) {
  if (n == 0) return 1;
  if (n == 1) return a % md;
  if (n % 2 == 0) {
    long long t = power(a, n / 2, md) % md;
    return (t * t) % md;
  }
  return ((a % md) * power(a, n - 1, md) % md) % md;
}
vector<bool> prime;
void sievefunc(long long n) {
  prime.assign(n + 1, 1);
  for (long long p = 2; p * p <= n; p++) {
    if (prime[p] == 1) {
      for (long long i = p * p; i <= n; i += p) prime[i] = 0;
    }
  }
}
vector<long long> primes;
void primenumbers_in_vec(long long n) {
  sievefunc(n);
  for (long long i = 2; i < n; i++)
    if (prime[i]) primes.push_back(i);
}
bool ispos(string s, long long till, long long tga, long long tqa,
           long long tgb, long long tqb) {
  long long ga = 0, qa = 0, gb = 0, qb = 0;
  for (long long i = 0; i <= till; i++) {
    if (i % 2 == 0) {
      if (s[i] == '1')
        ga++;
      else if (s[i] == '?')
        qa++;
    } else {
      if (s[i] == '1')
        gb++;
      else if (s[i] == '?')
        qb++;
    }
  }
  long long rem1 = 5 - (till + 2) / 2;
  long long rem2 = 5 - (till + 1) / 2;
  if (ga + qa > gb + rem2) return 1;
  if (gb + qb > ga + rem1) return 1;
  return 0;
}
void func() {
  string s;
  cin >> s;
  long long tga = 0, tqa = 0, tgb = 0, tqb = 0;
  for (long long i = 0; i < 10; i++) {
    if (i % 2 == 0) {
      if (s[i] == '1')
        tga++;
      else if (s[i] == '?')
        tqa++;
    } else {
      if (s[i] == '1')
        tgb++;
      else if (s[i] == '?')
        tqb++;
    }
  }
  for (long long i = 1; i <= 10; i++) {
    if (ispos(s, i, tga, tqa, tgb, tqb)) {
      cout << i + 1 << "\n";
      return;
    }
  }
  cout << 10 << "\n";
  return;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long test = 1;
  cin >> test;
  while (test--) func();
  return 0;
}
