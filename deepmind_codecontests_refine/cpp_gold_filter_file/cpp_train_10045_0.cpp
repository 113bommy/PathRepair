#include <bits/stdc++.h>
using namespace std;
long long n, k, d[99];
int main() {
  d[0] = d[1] = 1;
  for (int i = 2; i < 99; ++i) d[i] = d[i - 1] + d[i - 2];
  cin >> n >> k;
  --k;
  for (int i = 1; i <= n; ++i) {
    if (k < d[n - i])
      cout << i << " ";
    else {
      k -= d[n - i];
      cout << i + 1 << " " << i << " ";
      ++i;
    }
  }
  return 0;
}
