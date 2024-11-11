#include <bits/stdc++.h>
using namespace std;
long long int ncr(long long int n, long long int r) {
  if (n == r) return 1;
  if (r == 1) return n;
  return ncr(n - 1, r) + ncr(n - 1, r - 1);
}
long long int fact(long long int n) {
  long long int i, res = 1;
  for (i = 2; i <= n; i++) res *= i;
  return res;
}
int main() {
  long long int n, res;
  cin >> n;
  if (n == 2) cout << "1" << endl;
  if (n == 4)
    cout << "3" << endl;
  else {
    res = ncr(n, n / 2) / 2;
    long long int fa = fact(n / 2 - 1);
    res *= (fa * fa);
    cout << res << endl;
  }
  return 0;
}
