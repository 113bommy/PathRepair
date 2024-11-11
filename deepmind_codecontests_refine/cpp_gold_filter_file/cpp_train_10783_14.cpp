#include <bits/stdc++.h>
using namespace std;
long long f(long long x) {
  long long res = sqrt(2 * x) - 1;
  while (res * (res + 1) / 2 < x) ++res;
  return res;
}
int main() {
  long long n, m;
  cin >> n >> m;
  if (m >= n)
    cout << n;
  else
    cout << m + f(n - m);
  return 0;
}
