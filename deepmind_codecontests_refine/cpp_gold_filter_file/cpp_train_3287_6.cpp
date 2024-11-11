#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  long long n, m, k;
  cin >> n >> m >> k;
  long long i = 0LL, j = m + 1LL;
  long long X, Y;
  X = (k - 1LL), Y = (n - k);
  while (j - i > 1LL) {
    long long middle = (i + j) / 2LL;
    long long y = min(Y, middle);
    long long x = min(X, middle);
    long long quant =
        ((2LL * middle - y) * (y + 1LL) + (2LL * middle - x - 1LL) * x) / 2LL;
    if (quant <= m - n)
      i = middle;
    else
      j = middle;
  }
  cout << i + 1LL << endl;
  return 0;
}
