#include <bits/stdc++.h>
using namespace std;
const int N = 200010;
const long long INF = (long long)1e9 + 7;
long long fact[N];
long long mypow(long long a, long long x, long long mod) {
  long long ans = 1;
  while (x) {
    if (x & 1) {
      ans = (ans * a) % mod;
    }
    a = (a * a) % mod;
    x >>= 1;
  }
  return ans;
}
long long C(long long m, long long n) {
  long long a = fact[n];
  long long b = fact[m] * fact[n - m] % INF;
  return a * mypow(b, INF - 2, INF) % INF;
}
void init() {
  fact[0] = 1;
  for (int i = 1; i < N; i++) {
    fact[i] = i * fact[i - 1];
  }
}
int main() {
  init();
  int n;
  vector<int> a, b;
  cin >> n;
  a.resize(n);
  b.resize(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  if (n == 1) {
    cout << a[0] << endl;
    return 0;
  }
  if (n <= 3) {
    int op = 1;
    while (n) {
      for (int i = 0; i < n - 1; i++) {
        b[i] = (a[i] + op * a[i + 1] + INF) % INF;
        op *= -1;
      }
      n--;
      a = b;
    }
    cout << (a[0] + INF) % INF << endl;
  } else {
    int op = 1;
    while (n & 1) {
      for (int i = 0; i < n - 1; i++) {
        b[i] = (a[i] + op * a[i + 1] + INF) % INF;
        op *= -1;
      }
      n--;
      a = b;
    }
    long long lhs = 0, rhs = 0;
    for (int i = 0; i <= n / 2 - 1; i++) {
      lhs = (lhs + a[i * 2] * C(i, n / 2 - 1) % INF + INF) % INF;
      rhs = (rhs + a[i * 2 + 1] * C(i, n / 2 - 1) % INF + INF) % INF;
    }
    long long ans = 0;
    if ((n % 4 == 2 && op == 1) || (n % 4 == 0 && op == -1)) {
      ans = ((lhs + rhs) + INF) % INF;
    } else {
      ans = ((lhs - rhs) + INF) % INF;
    }
    cout << ans << endl;
  }
  return 0;
}
