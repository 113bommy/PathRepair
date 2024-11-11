#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n, m, k;
  cin >> n >> m >> k;
  long long int p = 2 * m;
  if (k % p == 0) {
    if (k % 2 == 0) {
      cout << (k / p) << " ";
      cout << m << " ";
    } else {
      cout << (k / p) + 1 << " ";
      cout << m << " ";
    }
  } else {
    cout << (k / p) + 1 << " ";
    if (abs(k % 2 == 0))
      cout << abs((k - (p * (k / p))) / 2) << " ";
    else
      cout << abs(((k - (p * (k / p))) / 2) + 1) << " ";
  }
  cout << ((k % 2 == 0) ? 'R' : 'L');
  return 0;
}
