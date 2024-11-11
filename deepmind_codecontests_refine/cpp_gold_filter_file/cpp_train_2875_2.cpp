#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, k, minimo, massimo;
  cin >> n >> k;
  if (k == 0) {
    cout << 0 << " " << 0;
    return 0;
  }
  if (3 * k > n)
    massimo = n - k;
  else
    massimo = 2 * k;
  if (n > k)
    minimo = 1;
  else
    minimo = 0;
  cout << minimo << " " << massimo;
  return 0;
}
