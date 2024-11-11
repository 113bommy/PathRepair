#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  if (n > 4) {
    cout << n << "\n";
    for (int i = 0; i < (n + 1) / 2; i++) cout << 2 * i + 1 << " ";
    for (int i = 0; i < n / 2; i++) cout << 2 * (i + 1) << " ";
  } else {
    if (n == 1 or n == 2)
      cout << 1 << "\n" << 1;
    else if (n == 3)
      cout << 2 << "\n"
           << "1 3";
    else
      cout << 3 << "\n"
           << "3 1 4";
  }
  return 0;
}
