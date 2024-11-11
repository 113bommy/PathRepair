#include <bits/stdc++.h>
using namespace std;
long long int power(long long int a, long long int b, long long int p) {
  long long int res = 1;
  a %= p;
  while (b != 0) {
    if (b % 2) res = (res % p * a % p) % p;
    b /= 2;
    a = (a % p * a % p) % p;
  }
  return res;
}
long long int gcd(long long int a, long long int b) {
  return b ? gcd(b, a % b) : a;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  int ar[10];
  ar[0] = 1;
  ar[4] = 1;
  ar[6] = 1;
  ar[8] = 2;
  ar[9] = 1;
  int k;
  cin >> k;
  bool pos = true;
  long long int num = 0;
  while (k) {
    if (k >= 2) {
      num = num * 10 + 8;
      k -= 2;
    } else {
      num = num * 10 + 0;
      k -= 1;
    }
    if (num > 1e18) {
      pos = false;
      break;
    }
  }
  if (pos == false)
    cout << -1 << "\n";
  else
    cout << num << "\n";
  return 0;
}
