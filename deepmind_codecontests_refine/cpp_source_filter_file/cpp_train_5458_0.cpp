#include <bits/stdc++.h>
using namespace std;
unsigned long long gcd(unsigned long long a, unsigned long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
unsigned long long lcm(unsigned long long a, unsigned long long b) {
  return a * b / gcd(a, b);
}
bool is_prime(unsigned long long n) {
  for (unsigned long long i = 2; i * i <= n; i++) {
    if (n % i == 0) return false;
  }
  return true;
}
void change(unsigned long long up1, unsigned long long down1,
            unsigned long long up2, unsigned long long down2,
            unsigned long long& up, unsigned long long& down, bool type) {
  down = lcm(down1, down2);
  if (type)
    up = up1 * (down / down1) - up2 * (down / down2);
  else
    up = up1 * (down / down1) + up2 * (down / down2);
  unsigned long long g = gcd(up, down);
  up /= g;
  down /= g;
}
int main() {
  ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    unsigned long long n;
    cin >> n;
    unsigned long long up = 1, down = 2;
    unsigned long long pk = n, pk1 = n + 1;
    while (!is_prime(pk)) pk--;
    while (!is_prime(pk1)) pk1++;
    change(up, down, n - pk + 1, pk * pk1, up, down, false);
    change(up, down, 1, pk, up, down, true);
    cout << up << '/' << down << '\n';
  }
  return 0;
}
