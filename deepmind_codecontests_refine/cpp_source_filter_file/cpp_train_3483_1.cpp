#include <bits/stdc++.h>
using namespace std;
const long long mod = (int)1000000007;
const long long n = 100010;
long long k;
long long mem[n];
long long s[n];
int main() {
  long long t;
  cin >> t >> k;
  for (long long i = 0; i < k; ++i) mem[i] = 1;
  for (long long i = k; i < n; ++i) mem[i] = (mem[i - 1] + mem[i - k]) % mod;
  s[0] = 0;
  for (long long i = 1; i < n; ++i) s[i] = (s[i - 1] + mem[i]) % mod;
  for (long long i = 0; i < t; ++i) {
    long long a, b;
    cin >> a >> b;
    cout << (s[b] - s[a - 1]) % mod << endl;
  }
}
