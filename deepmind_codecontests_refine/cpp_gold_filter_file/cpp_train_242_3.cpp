#include <bits/stdc++.h>
const long long template_array_size = 1e6;
const long long INF = 9223372036854775807;
const long long MOD = 1e9 + 7;
using namespace std;
long long n, m, k, x, a, b;
long long gcd(long long a, long long b) {
  long long t;
  while (b != 0) {
    t = b;
    b = a % b;
    a = t;
  }
  return a;
}
long long lcm(long long a, long long b) {
  if (a > b)
    return (a / gcd(a, b)) * b;
  else
    return (b / gcd(a, b)) * a;
}
vector<long long> v, v2;
void solve() {
  cin >> n;
  if (n < 3) {
    cout << n;
  } else {
    if (n % 2 == 0) {
      cout << max((n * (n - 1) * (n - 3)) / gcd(n, n - 3),
                  (n - 1) * (n - 2) * (n - 3));
    } else {
      cout << n * (n - 1) * (n - 2);
    }
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int T = 1;
  while (T--) {
    solve();
  }
  return 0;
}
