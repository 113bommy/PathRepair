#include <bits/stdc++.h>
using namespace std;
int inf = 2147483647;
const long long ll = 9223372036854775807, ninf = 1000000000;
const double eps = 1e-6;
const long long nll = 223372036854775807;
int key[] = {1, 2, 9, 64, 625, 7776, 117649, 2097152};
int main() {
  int mod = 1000000007;
  int a, b;
  while (cin >> a >> b) {
    long long ans = key[b];
    long long n = a - b;
    for (int i = 0; i < a - b; i++) {
      ans *= n;
      ans %= mod;
    }
    cout << ans << '\n';
  }
  return 0;
}
