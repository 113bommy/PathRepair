#include <bits/stdc++.h>
using namespace std;
long long int fact[200005];
long long int power(long long int a, long long int b) {
  if (b == 0) return 1;
  if (b == 1) return a % 998244353;
  if (b % 2 == 1)
    return (a % 998244353 * power((a * a) % 998244353, (b - 1) / 2) %
            998244353) %
           998244353;
  return power((a * a) % 998244353, b / 2) % 998244353;
}
long long int ncr(long long int n, long long int r) {
  long long int num = fact[n];
  long long int den = (fact[r] * fact[n - r]) % 998244353;
  long long int inv = power(den, 998244353 - 2) % 998244353;
  return (num * inv) % 998244353;
}
void pre() {
  fact[1] = 1;
  for (int i = 2; i < 200005; i++) {
    fact[i] = (fact[i - 1] * i) % 998244353;
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  pre();
  long long int n, m;
  cin >> n >> m;
  if (n == 2) {
    cout << 0 << "\n";
    return 0;
  }
  long long int p = ncr(m, n - 1) % 998244353;
  p = (p * (n - 2) % 998244353) % 998244353;
  p = (p * power(2, n - 3) % 998244353) % 998244353;
  ;
  cout << p << "\n";
}
