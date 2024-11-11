#include <bits/stdc++.h>
using namespace std;
int main() {
  int k;
  cin >> k;
  int a[k + 9];
  for (int i = 0; i < k; i++) cin >> a[i];
  for (int i = 0; i < k; i++)
    if (a[i] == 1 or a[i] == 2)
      cout << '0' << '\n';
    else if (a[i] % 2 == 1)
      cout << a[i] / 2 << '\n';
    else
      cout << (a[i] / 2) - 1 << '\n';
  return 0;
}
