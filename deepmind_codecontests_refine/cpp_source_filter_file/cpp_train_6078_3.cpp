#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007ll;
long long n, k;
long long pow(long long a, long long b) {
  long long c = 1;
  for (int i = 0; i < b; i++) c = (c * a) % MOD;
  return c;
}
int main() {
  if (true)
    freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout);
  cin >> n >> k;
  cout << (pow(k, k - 1) * pow(n - k, n - k)) % MOD;
  return 0;
}
