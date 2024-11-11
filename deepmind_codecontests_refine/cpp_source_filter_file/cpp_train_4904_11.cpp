#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  long long n;
  cin >> n;
  for (long long i = 2; i <= n; ++i) {
    if ((n + 1) * n / 2 % i == 0) {
      cout << "YES\n";
      cout << 1 << ' ' << i << '\n';
      cout << (n - 1) << ' ';
      for (int j = 1; j <= n; ++j)
        if (j != i) {
          cout << j << ' ';
        }
      cout << '\n';
      exit(0);
    }
  }
  cout << "No\n";
}
