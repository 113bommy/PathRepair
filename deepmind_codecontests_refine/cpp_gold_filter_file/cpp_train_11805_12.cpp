#include <bits/stdc++.h>
using namespace std;
long long expo(long long a, long long b, long long m) {
  long long result = 1;
  while (b) {
    if (b & 1) {
      result = (result * a) % m;
    }
    b = (b >> 1) % m;
    a = (a * a) % m;
  }
  return result;
}
double expof(double a, int b) {
  double result = 1;
  while (b) {
    if (b & 1) {
      result = (result * a);
    }
    b = (b >> 1);
    a = (a * a);
  }
  return result;
}
bool isprime(long long p) {
  long long s = sqrt(p);
  if (p % 2 == 0 || p <= 2) return false;
  for (int i = 3; i <= s; i += 2) {
    if (p % i == 0) {
      return false;
    }
  }
  return true;
}
int main() {
  int n, m, k, a[100005], b[100005];
  cin >> n >> m >> k;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  for (int i = 0; i < m; ++i) {
    cin >> b[i];
  }
  if (n > m)
    cout << "YES" << endl;
  else {
    sort(a, a + n);
    sort(b, b + m);
    int j = 0;
    for (int i = 0 + m - n; i < m; ++i, j++) {
      if (a[j] > b[i]) {
        cout << "YES" << endl;
        return 0;
      }
    }
    cout << "NO" << endl;
  }
}
