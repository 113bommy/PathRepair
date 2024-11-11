#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, k;
  cin >> n >> m >> k;
  if (!(n & 1)) {
    cout << "Marsel";
    return 0;
  }
  if (k == 1 && m > 1) {
    cout << "Timur";
    return 0;
  }
  for (int i = 2; i * i < m && m / i >= k; i++)
    if (!(m % i)) {
      cout << "Timur";
      return 0;
    }
  cout << "Marsel";
  return 0;
}
