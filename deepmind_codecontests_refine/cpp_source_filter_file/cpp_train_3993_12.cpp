#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, a, k, e;
  cin >> n >> m >> a;
  if (n % a == 0)
    k = n / a;
  else
    k = n / a + 1;
  if (m % a == 0)
    e = m / a;
  else
    e = m / a + 1;
  cout << e * k;
  return 0;
}
