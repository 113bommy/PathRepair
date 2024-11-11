#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, m, i, j, k;
  cin >> n;
  double ans = 0;
  for (i = 0; i < n; i++) {
    cin >> k;
    ans += (double)k / 100.0;
  }
  std::cout << std::fixed;
  std ::cout << setprecision(5);
  cout << ans / n;
  return 0;
}
