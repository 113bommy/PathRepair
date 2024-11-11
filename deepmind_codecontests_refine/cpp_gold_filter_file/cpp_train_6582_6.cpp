#include <bits/stdc++.h>
using namespace std;
long long c(int n, int k) {
  if (k > n) return 0;
  if (k * 2 > n) k = n - k;
  if (k == 0) return 1;
  long long result = n;
  for (int i = 2; i <= k; ++i) {
    result *= (n - i + 1);
    result /= i;
  }
  return result;
}
int main() {
  int n, m, t;
  long long tot = 0;
  cin >> n >> m >> t;
  for (int b = 4; b <= n; ++b) {
    int g = t - b;
    if (g >= 1) {
      tot += c(n, b) * c(m, g);
    }
  }
  cout << tot << endl;
  return 0;
}
