#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:256000000")
using namespace std;
const double infd = 2e+9;
const int infi = INT_MAX;
template <class T>
inline T sqr(T x) {
  return x * x;
}
bool is_prime(int x) {
  for (int i = 2; i < (int)sqrt(x) + 1; i++) {
    if (x % i == 0) return false;
  }
  return true;
}
long long gcd(long long a, long long b) { return a == 0 ? b : gcd(b % a, a); }
long long Gcd(long long a, long long b) {
  if (a > b) swap(a, b);
  return gcd(a, b);
}
int main() {
  ios_base::sync_with_stdio(false);
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    int n;
    cin >> n;
    int upper = n + 1, lower = n;
    while (!is_prime(upper)) upper++;
    while (!is_prime(lower)) lower--;
    long long p = lower * 1ll * upper - 2 * (lower + upper) + 2 * (n + 1);
    long long q = 2ll * lower * upper;
    long long g = Gcd(p, q);
    cout << (p / g) << '/' << (q / g) << endl;
  }
  return 0;
}
