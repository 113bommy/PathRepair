#include <bits/stdc++.h>
using namespace std;
long long GCD(long long A, long long B) {
  if (B == 0) return A;
  return GCD(B, A % B);
}
bool isPrime(int a) {
  for (int i = 2; i <= sqrt(a); i++) {
    if (a % i == 0) return false;
  }
  return true;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int v, u;
    v = n;
    while (!isPrime(v)) v--;
    u = n + 1;
    while (!isPrime(u)) u++;
    long long p = 2 * (n + 1) - 2 * (u + v) + u * v;
    long long q = 2 * u * v;
    long long gcd = GCD(p, q);
    cout << p / gcd << "/" << q / gcd << endl;
  }
}
