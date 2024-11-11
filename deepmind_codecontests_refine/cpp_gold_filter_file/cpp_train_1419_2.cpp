#include <bits/stdc++.h>
using namespace std;
long long int gcd(long long int a, long long int b) {
  if (b > a) swap(a, b);
  if (a % b == 0)
    return b;
  else
    return gcd(b, a % b);
}
long long int a, b, k, k1, k2;
int main() {
  cin >> a >> b;
  k = (a * b) / gcd(a, b);
  k1 = k / a;
  k2 = k / b;
  if (abs(k1 - k2) == 1)
    cout << "Equal";
  else if (k1 > k2)
    cout << "Dasha";
  else
    cout << "Masha";
  return 0;
}
