#include <bits/stdc++.h>
const int MOD = 1000000009;
using namespace std;
long long Two(int k) {
  if (k == 0) return 1;
  long long ans = Two(k / 2);
  if (k % 2 == 0) return (ans * ans) % MOD;
  return (ans * ans * 2) % MOD;
}
int main() {
  long long n, m, k;
  cin >> n >> m >> k;
  long long l = n - m;
  if (l * k + k - 1 >= n) {
    cout << m;
  } else {
    long long good = (n / k - l);
    long long ans = ((Two(good + 1) - 2 + MOD) * k) % MOD;
    cout << (ans + m - good * k + MOD) % MOD;
  }
  return 0;
}
