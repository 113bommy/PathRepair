#include <bits/stdc++.h>
using namespace std;
const long long int sz = 1e9 + 7;
const long long int inf = 1e9;
const double pi = acos(-1);
int gcd(long long int a, long long int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
bool isPrime(long long int n) {
  if (n == 1) return false;
  for (long long int i = 2; i * i <= n; i++) {
    if (n % i == 0) return false;
  }
  return true;
}
bool isPowerofTwo(long long int n) {
  if (n == 0) return 0;
  while (n != 1) {
    if (n % 2 != 0) return 0;
    n = n / 2;
  }
  return 1;
}
void solve() {
  long long int n, m;
  cin >> n >> m;
  map<string, string> make_pair;
  string a, b;
  while (m--) {
    cin >> a >> b;
    if (a.size() >= b.size()) {
      make_pair[a] = b;
    } else {
      make_pair[a] = a;
    }
  }
  while (n--) {
    cin >> a;
    cout << make_pair[a] << " ";
  }
}
int main() {
  solve();
  return 0;
}
