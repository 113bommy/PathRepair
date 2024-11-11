#include <bits/stdc++.h>
using namespace std;
int main() {
  unsigned long long n, k, c = 0;
  cin >> n >> k;
  unsigned long long l, r = k / 2 + 1;
  if (k % 2 == 0)
    l = k / 2 - 1;
  else
    l = k / 2;
  if ((2 * n) - 1 < k)
    cout << 0;
  else
    cout << min(l, n - r + 1);
  return 0;
}
