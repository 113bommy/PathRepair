#include <bits/stdc++.h>
using namespace std;
long long mod = 998244353;
long long p[200009];
int main() {
  long long n;
  cin >> n;
  p[0] = 1;
  for (int i = 1; i <= n; i++) p[i] = 10 * p[i - 1] % mod;
  for (int i = 1; i <= n - 1; i++) {
    long long m = n - i - 1;
    long long A = 0, B = 0;
    if (i < n - 1) A = m * 180 % mod * p[n - i - 2] % mod;
    B = 180 * p[n - i - 1] % mod;
    cout << (A + B) % mod << " ";
  }
  cout << 10 << endl;
}
