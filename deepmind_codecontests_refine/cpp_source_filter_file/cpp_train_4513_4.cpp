#include <bits/stdc++.h>
using namespace std;
struct edge {
  long long A;
  long long B;
};
long long power(long long a, long long b, long long mod) {
  long long x = 1, y = a;
  while (b > 0) {
    if (b % 2) {
      x = (x * y) % mod;
    }
    y = (y * y) % mod;
    b /= 2;
  }
  return x % mod;
}
long long modular_inverse(long long n, long long mod) {
  return power(n, mod - 2, mod);
}
bool edgecompare(edge lhs, edge rhs) {
  if (lhs.B != rhs.B)
    return lhs.B < rhs.B;
  else
    return lhs.A < rhs.A;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cout << setprecision(25);
  long long i, n, m, j;
  cin >> n;
  long long a[n + 5], b, c[n + 5];
  for (i = 0; i < n; i++) {
    cin >> b;
    a[b] = i;
  }
  for (i = 0; i < n; i++) {
    cin >> b;
    c[a[b]] = i + 1;
  }
  i = 0;
  while (i < n && c[i + 1] > c[i]) {
    i++;
  }
  cout << n - i - 1;
  return 0;
}
