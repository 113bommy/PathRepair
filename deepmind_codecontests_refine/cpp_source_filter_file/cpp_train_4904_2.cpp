#include <bits/stdc++.h>
using namespace std;
long long n, k;
int main() {
  ios_base::sync_with_stdio(false);
  cin >> n;
  if (n <= 2) return cout << "No", 0;
  k = (n * (n + 1)) / 2;
  for (long long y = 2; y * y <= k; y++) {
    if (!(k % y)) {
      cout << "Yes" << endl;
      cout << 1 << ' ' << y << endl;
      cout << n - 1 << ' ';
      for (long long i = 1; i <= n; i++)
        if (i != k) cout << i << ' ';
      return 0;
    }
  }
  cout << "No";
}
