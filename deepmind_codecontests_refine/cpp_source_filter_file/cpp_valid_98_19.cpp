#include <bits/stdc++.h>
using namespace std;
bool even(long long int x) { return (x % 2 == 0); }
bool odd(long long int x) { return (x % 2 != 0); }
vector<int> sieve(int n) {
  bool prime[n + 1];
  memset(prime, true, sizeof(prime));
  for (int p = 2; p * p <= n; p++) {
    if (prime[p] == true) {
      for (int i = p * p; i <= n; i += p) prime[i] = false;
    }
  }
  vector<int> v;
  for (int p = 2; p <= n; p++)
    if (prime[p]) v.push_back(p);
  return v;
}
long long gcd(long long int a, long long int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
bool isprime(long long n) {
  if (n == 1) return false;
  if (n == 2 || n == 3) return true;
  if (n % 2 == 0 || n % 3 == 0) return false;
  for (long long i = 5; i * i <= n; i = i + 6) {
    if (n % i == 0 || n % (i + 2) == 0) return false;
  }
  return true;
}
long long lcm(int a, int b) { return (a / gcd(a, b)) * b; }
bool compare(pair<int, int> p1, pair<int, int> p2) {
  if (p1.first == p2.first)
    return p1.second <= p2.second;
  else
    return p1.first > p2.first;
}
vector<int> presum(vector<long long int> v) {
  vector<int> res(v.size());
  res[0] = v[0];
  for (int i = 1; i < v.size(); i++) {
    res[i] = res[i - 1] + v[i];
  }
  return res;
}
void precision(int a) { cout << setprecision(a) << fixed; }
int main() {
  int t;
  cin >> t;
  while (t--) {
    int f = 0;
    int n;
    cin >> n;
    string s;
    cin >> s;
    int l = 0, r = 0;
    for (int i = 0; i < n; i++) {
      int a = 0, b = 0;
      for (int j = i; j < n; j++) {
        if (s[j] == 'a') a++;
        if (s[j] == 'b') b++;
        if (a == b && (a != 0 && b != 0)) {
          l = i;
          r = j;
          f = 1;
          break;
        }
      }
      if (f == 1) break;
    }
    if (f == 1)
      cout << l + 1 << " " << r + 1 << endl;
    else
      cout << "-1" << endl;
  }
}
