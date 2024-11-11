#include <bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int MOD = 1e9 + 7;
const int N = 300005, M = N;
int power(int a, int b) {
  if (b == 0) return 1;
  if (b == 1) return a;
  if (b % 2 == 1) return (power(a, b - 1) * a) % 998244353;
  int q = power(a, b / 2);
  return (q * q) % 998244353;
}
long long n, m;
int main() {
  int n, m;
  cin >> n;
  int c = 0, i;
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    c = c ^ x;
  }
  int g[n + 2];
  g[0] = 0;
  for (int i = 1; i <= n; ++i) {
    g[i] = i ^ g[i - 1];
  }
  for (int i = 1; i <= n; ++i) {
    if ((n / i) % 2 != 0) {
      c = c ^ g[i - 1];
    }
    if (n % i) {
      c = c ^ g[n % i];
    }
  }
  cout << c;
}
