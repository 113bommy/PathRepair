#include <bits/stdc++.h>
using namespace std;
const int mod = 1000003;
long long p[1200005];
void build() {
  p[0] = 1;
  for (int i = 1; i < 1200005; i++) {
    p[i] = i * p[i - 1] % mod;
  }
}
long long mypow(long long a, int x) {
  if (x == 0) return 1;
  if (x & 1)
    return mypow(a * a % mod, x / 2) * a % mod;
  else
    return mypow(a * a % mod, x / 2) % mod;
}
long long C(int n, int m) {
  return (p[n] * mypow(p[m], mod - 2) % mod) * mypow(p[n - m], mod - 2) % mod;
}
int main() {
  int n, m;
  cin >> n >> m;
  build();
  long long sum = 0;
  for (int i = n; i >= 1; i--) {
    sum = sum + C(i + m - 1, m - 1);
    sum %= mod;
  }
  cout << sum << endl;
  return 0;
}
