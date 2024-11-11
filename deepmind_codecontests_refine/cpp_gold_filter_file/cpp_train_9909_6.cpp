#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int i, n, d, e;
  cin >> n >> d >> e;
  e *= 5;
  int min = n % e;
  for (i = 0; i <= n / d; i++) {
    if ((n - (i * d)) % e < min) min = (n - (i * d)) % e;
  }
  if ((n % e) % d < min) min = (n % e) % d;
  cout << min;
  return 0;
}
