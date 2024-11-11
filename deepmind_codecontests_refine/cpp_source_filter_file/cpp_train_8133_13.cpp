#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  cin >> n >> k;
  if (n - k <= k)
    cout << 4 * n - k;
  else
    cout << n + n + n + k - 1;
  return 0;
}
