#include <bits/stdc++.h>
using namespace std;
int main() {
  long long m, n, a, prod{1};
  cin >> m >> n >> a;
  if (m % a == 0)
    prod *= m / a;
  else
    prod *= ((m / a) + 1);
  if (n % a == 0)
    prod *= n / a;
  else
    prod *= ((n / a) + 1);
  cout << prod;
  return 0;
}
