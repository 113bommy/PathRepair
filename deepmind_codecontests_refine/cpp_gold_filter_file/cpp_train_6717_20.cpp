#include <bits/stdc++.h>
using namespace std;
static int rowNbr[] = {-1, -1, -1, 0, 0, 1, 1, 1};
static int colNbr[] = {-1, 0, 1, -1, 1, -1, 0, 1};
long long int power(long long int base, long long int p) {
  long long int ans = 1;
  while (p) {
    if (p & 1) ans = (ans * base);
    base = (base * base);
    p /= 2;
  }
  return ans;
}
long long int modPower(long long int base, long long int p,
                       long long int mod = (1000000007LL)) {
  long long int ans = 1;
  while (p) {
    if (p & 1) ans = (ans * base) % mod;
    base = (base * base) % mod;
    p /= 2;
  }
  return ans;
}
long long int gcd(long long int a, long long int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
set<long long int> X;
set<long long int> Y;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  cout << power(2, 1 + n) - 2;
}
