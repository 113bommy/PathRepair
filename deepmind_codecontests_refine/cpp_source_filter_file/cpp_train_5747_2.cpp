#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;
template <typename... T>
void input(T&... t) {
  ((cin >> t), ...);
}
template <typename T>
void printV(T vec) {
  for (long long i = 0; i < (long long)vec.size(); i++)
    cout << vec[i] << " " << flush;
}
bool isPrime(long long n) {
  if (n == 2 or n == 3 or n == 5 or n == 7) return true;
  if (n % 2 == 0 or n % 3 == 0 or n % 5 == 0 or n % 7 == 0) return false;
  int count = 0;
  for (long long i = 2; i < sqrt(n); i++) {
    if (n % i == 0) count++;
  }
  if (count == 0)
    return true;
  else
    return false;
}
long long g(long long a, long long b) {
  if (b == 0) return a;
  return g(b, a % b);
}
long long gcd(vector<long long> vec) {
  long long t = vec[0];
  for (long long i = 1; i < (long long)vec.size(); i++) {
    t = g(t, vec[i]);
  }
  return t;
}
int main() {
  cout << setprecision(16);
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long n;
  cin >> n;
  if (isPrime(n))
    cout << n << endl;
  else {
    vector<long long> fact;
    for (long long i = 2; i <= sqrt(n); i++) {
      if (i * i == n)
        fact.push_back(i);
      else if (n % i == 0) {
        fact.push_back(i);
        fact.push_back(n / i);
      }
    }
    fact.push_back(n);
    sort(fact.begin(), fact.end());
    long long g = gcd(fact);
    if (g == 1)
      cout << 1 << endl;
    else
      cout << fact[0] << endl;
  }
  return 0;
}
