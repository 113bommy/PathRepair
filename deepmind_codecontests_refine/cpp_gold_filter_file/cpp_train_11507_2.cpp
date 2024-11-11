#include <bits/stdc++.h>
long long ans, n, m, i, j, k, a[10];
using namespace std;
long long c(long long n, long long m) {
  long long h, t;
  long long i;
  h = 1;
  if (m == 7 && n > 500) {
    for (i = n - m + 1; i <= n - 1; i++) h *= i;
    t = h / a[6] * n / 7;
    return t;
  }
  for (i = n - m + 1; i <= n; i++) h *= i;
  return h / a[m];
}
int main(int argc, const char* argv[]) {
  cin >> n;
  a[1] = 1;
  for (i = 2; i <= 7; i++) a[i] = a[i - 1] * i;
  cout << c(n, 5) + c(n, 6) + c(n, 7) << endl;
  return 0;
}
