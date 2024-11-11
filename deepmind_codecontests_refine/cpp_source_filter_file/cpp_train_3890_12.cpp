#include <bits/stdc++.h>
using namespace std;
long long int powerbinaryexponentiation(long long int a, long long int n,
                                        long long int mod) {
  long long int res = 1;
  while (n) {
    if (n % 2) {
      res = (res * a) % mod;
      n--;
    } else {
      a = (a * a) % mod;
      n = n / 2;
    }
  }
  return res;
}
int main() {
  long long int n, m;
  cin >> n >> m;
  cout << (powerbinaryexponentiation(3, n, m) % m - 1 % m) % m;
}
