#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  if (n == 1) {
    cout << 1;
    return 0;
  }
  if (n <= 3 || n % 4 == 2 || n % 4 == 3) {
    cout << -1;
    return 0;
  }
  if (n % 4 == 0) {
    for (int i = 0; i < n / 4; i++)
      cout << 2 * i + 2 << " " << n - 2 * i << " ";
    for (int i = 0; i < n / 4; i++)
      cout << n / 2 - 1 - 2 * i << " " << n / 2 + 1 + 2 * i;
  }
  if (n % 4 == 1) {
    for (int i = 0; i < n / 4; i++)
      cout << 2 * i + 2 << " " << n - 2 * i << " ";
    cout << n / 2 + 1 << " ";
    for (int i = 0; i < n / 4; i++)
      cout << n / 2 - 1 - 2 * i << " " << n / 2 + 2 + 2 * i << " ";
  }
  return 0;
}
