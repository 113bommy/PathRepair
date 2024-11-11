#include <bits/stdc++.h>
using namespace std;
int n, i, j, k, l, o;
int main() {
  cin >> n >> k;
  if (n <= 3)
    if (k < n)
      cout << 1;
    else
      cout << 0;
  else {
    if (k == 1)
      cout << 1;
    else if (k == 2)
      cout << 2;
    else if (n / 2 >= k)
      cout << max(k, 1);
    else
      cout << n - k;
  }
  return 0;
}
