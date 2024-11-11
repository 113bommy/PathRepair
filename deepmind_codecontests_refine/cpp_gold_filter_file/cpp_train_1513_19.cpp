#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  long long n;
  long double k;
  cin >> n >> k;
  k = (pow(1.000000011, k) - 1.);
  cout << setprecision(6) << fixed << n + n * k;
  return 0;
}
