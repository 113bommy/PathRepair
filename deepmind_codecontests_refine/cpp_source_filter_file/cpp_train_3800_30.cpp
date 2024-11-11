#include <bits/stdc++.h>
using namespace std;
long long a[300000], n, i, sum, k, x, t;
int main() {
  cin >> n >> x;
  t = sqrt(x);
  if (t * t == x && x <= n) k++;
  t--;
  for (i = 1; i <= min(n, t); i++) {
    if (x % i == 0 && x / i <= n) k += 2;
  }
  cout << k;
}
