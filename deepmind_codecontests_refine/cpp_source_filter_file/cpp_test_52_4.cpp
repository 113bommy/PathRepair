#include <bits/stdc++.h>
using namespace std;
const int N = 4e5 + 5;
int MOD = 1e9 + 7;
long long fast_power(long long base, long long power) {
  long long result = 1;
  while (power > 0) {
    if (power % 2 == 1) {
      result = (result * base) % MOD;
    }
    base = (base * base) % MOD;
    power = power / 2;
  }
  return result;
}
int n, k;
bool get(int index) {
  long long get = fast_power(2, index);
  if (k < get) return 0;
  if (get == 1) return k % 2;
  return ((k / get) % 2);
}
int main() {
  int test;
  cin >> test;
  while (test--) {
    cin >> n >> k;
    long long sum = 0;
    for (int i = 0; i <= 32; ++i) {
      if ((k >> i) & 1) {
        sum = (sum % MOD + fast_power(n, i) % MOD) % MOD;
      }
    }
    cout << sum % MOD << "\n";
  }
  return 0;
}
