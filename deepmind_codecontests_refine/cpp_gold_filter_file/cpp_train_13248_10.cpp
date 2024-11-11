#include <bits/stdc++.h>
const long long mod = 1e9 + 7;
using namespace std;
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
long long ksm(long long a, long long b) {
  long long ret = 1;
  while (b) {
    if (b & 1) ret = ret * a % mod;
    a = a * a % mod;
    b >>= 1;
  }
  return ret;
}
int t;
int main() {
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    if (n == 1) {
      printf("1\n");
      continue;
    }
    printf("%d\n", n / 2 + 1);
  }
  return 0;
}
