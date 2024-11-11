#include <bits/stdc++.h>
using namespace std;
void solve();
int gcd(int a, int b) {
  if (b == 0)
    return a;
  else
    return gcd(b, a % b);
}
bool isPrime(long long int a) {
  for (int i = 2; i <= sqrt(a); i++) {
    if (a % i == 0) return false;
  }
  return true;
}
int digit(long long int a) {
  long long int n = a;
  int an = 0;
  while (n >= 9) {
    an++;
    n /= 10;
  }
  if (pow(10, an) - 1 == a) {
    an++;
  }
  return an;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long int a, b;
    cin >> a >> b;
    int c = digit(b);
    cout << (c * a) << "\n";
  }
  return 0;
}
void solve() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  return;
}
