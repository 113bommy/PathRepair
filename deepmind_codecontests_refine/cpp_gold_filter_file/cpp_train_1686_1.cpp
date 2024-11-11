#include <bits/stdc++.h>
using namespace std;
long long n, k, n1, n2;
int main() {
  cin >> n;
  k = n * n;
  n1 = n / 2;
  n2 = n % 2;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n1; j++) cout << n1 * (i - 1) + j << ' ';
    for (int j = 1; j <= n1; j++) cout << k - n1 * (i - 1) - j + 1 << ' ';
    if (n2) cout << n * (n - 1) / 2 + i << ' ';
    cout << endl;
  }
}
