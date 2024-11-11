#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    long long n, m, k;
    cin >> m >> n >> k;
    if (m % 2 == 0 && n % 2 == 0 && k % 2 == 0)
      cout << "YES" << '\n';
    else if (m % 2 == 0 && n % 2 != 0 && k % 2 == 0 && k <= (m * (n - 1)) / 2)
      cout << "YES" << '\n';
    else if (m % 2 != 0 && n % 2 == 0 && (k - n / 2) % 2 == 0 && k >= n)
      cout << "YES" << '\n';
    else
      cout << "NO" << '\n';
  }
}
