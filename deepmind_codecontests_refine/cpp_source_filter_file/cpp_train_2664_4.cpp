#include <bits/stdc++.h>
using namespace std;
int maxi(long long int a, long long int b) { return (a > b ? a : b); }
int mini(long long int a, long long int b) { return (a < b ? a : b); }
int prime[1000001] = {0};
void sieve_of_erastosthenes(long long int n) {
  long long int p;
  for (p = 2; p * p <= n; p++) {
    if (prime[p] == 0) {
      for (long long int i = p * 2; i <= n; i += p) prime[i] = 1;
    }
  }
}
string toBinary(int n) {
  std::string r;
  while (n != 0) {
    r = (n % 2 == 0 ? "0" : "1") + r;
    n /= 2;
  }
  return r;
}
long long int fac(long long int x, long long int y) {
  long long int product = 1;
  long long int j = 1;
  for (int i = max(y, x - y) + 1; i <= x; i++) {
    product *= i;
    product /= j;
    j++;
  }
  return product;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  string s = "ROYGBIV";
  int n;
  cin >> n;
  int d = n / 7;
  int l = n % 7;
  for (int i = 0; i < d; i++) cout << s;
  switch (l) {
    case (0):
      break;
    case (1):
      cout << 'G';
      break;
    case (2):
      cout << "YG";
      break;
    case (3):
      cout << "YGB";
      break;
    case (4):
      cout << "OYGB";
      break;
    case (5):
      cout << "OYGBIV";
      break;
    case (6):
      cout << "ROYGBI";
      break;
  }
  return 0;
}
