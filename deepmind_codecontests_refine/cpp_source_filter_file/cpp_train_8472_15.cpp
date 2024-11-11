#include <bits/stdc++.h>
using namespace std;
int main() {
  unsigned long long n, i, k;
  cin >> n >> k;
  if (n % 2 == 1)
    if (k > n / 2 + 1)
      cout << 2 * (k - n / 2 - 1);
    else
      cout << 2 * k - 1;
  else if (k > n / 2 + 1)
    cout << 2 * (k - n / 2);
  else
    cout << 2 * k - 1;
  cout << endl;
  return 0;
}
