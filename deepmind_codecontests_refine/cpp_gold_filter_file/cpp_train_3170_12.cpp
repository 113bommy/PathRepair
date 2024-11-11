#include <bits/stdc++.h>
using namespace std;
const double PI = 3.141592654;
long long gcd(long long a, long long b) { return !b ? a : gcd(b, a % b); }
long long lcm(long long a, long long b) { return (a / gcd(a, b)) * b; }
long long fib(int n) {
  return (((1 / sqrt(5)) * (pow((1 + sqrt(5)) / 2, n)) -
           ((1 / sqrt(5)) * (pow((1 - sqrt(5)) / 2, n)))));
}
void fast() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL), cout.tie(NULL);
}
bool isPrime(int x) {
  for (int i = 1; i * i <= x; i++) {
    if (x % i == 0) return 0;
  }
  return 1;
}
int main() {
  fast();
  int mx = 0;
  int x;
  cin >> x;
  map<string, int> mp;
  string s, ans;
  for (int(i) = 0; (i) < (long long)(x); (i)++) {
    cin >> s;
    mp[s]++;
    if (mp[s] > mx) mx = mp[s], ans = s;
  }
  cout << ans;
  return 0;
}
