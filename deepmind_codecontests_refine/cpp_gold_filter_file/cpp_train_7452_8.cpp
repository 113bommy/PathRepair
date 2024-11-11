#include <bits/stdc++.h>
using namespace std;
int k, n, m;
int p(int x) {
  for (int i = 2; i <= sqrt(m); i++) {
    if (m % i == 0 && m / i >= k) return 1;
  }
  if (k == 1) return 1;
  return 0;
}
int main() {
  cin >> n >> m >> k;
  if (n % 2 == 0 || m == 1) {
    cout << "Marsel";
    return 0;
  }
  if (p(m) == 1)
    cout << "Timur";
  else
    cout << "Marsel";
  return 0;
}
