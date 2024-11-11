#include <bits/stdc++.h>
using namespace std;
long long int gcd(long long int a, long long int b) {
  if (a == 0) return b;
  return gcd(b % a, a);
}
long long int lcm(long long int a, long long int b) {
  return (max(a, b) / gcd(a, b)) * min(a, b);
}
void build() {}
long long int modexp(long long int base, long long int exponent,
                     long long int modulus) {
  if (modulus == 1) return 0;
  long long int result = 1;
  base = base % modulus;
  while (exponent > 0) {
    if (exponent % 2 == 1) {
      result = (result * base) % modulus;
    }
    exponent = exponent >> 1;
    base = (base * base) % modulus;
  }
  return result;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  build();
  string s;
  cin >> s;
  int flag = 0, count = 0;
  for (int i = s.length() - 1; i >= 0; i--) {
    if (s[i] == '0') count++;
    if (count >= 5) {
      if (s[i] == '1') flag = 1;
    }
  }
  if (flag == 1)
    cout << "yes";
  else
    cout << "no";
}
