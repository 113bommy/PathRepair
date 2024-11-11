#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, m;
  cin >> n >> m;
  long long kmax, kmin;
  kmax = ((n - m + 1) * (n - m)) / 2;
  kmin = ((n / m) * (n / m - 1)) / 2 * m + n / m * n % m;
  cout << kmin << " " << kmax;
}
