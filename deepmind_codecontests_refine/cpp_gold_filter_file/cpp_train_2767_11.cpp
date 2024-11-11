#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n;
  cin >> n;
  int k;
  cin >> k;
  if (k == 0) {
    if (n % 6 == 0 || n % 6 == 5)
      cout << 0;
    else if (n % 6 == 1 || n % 6 == 2)
      cout << 1;
    else
      cout << 2;
  } else if (k == 1) {
    if (n % 3 == 0)
      cout << 1;
    else if (n % 3 == 1)
      cout << 0;
    else
      cout << 2;
  } else {
    if (n % 6 == 0 || n % 6 == 1)
      cout << 2;
    else if (n % 6 == 2 || n % 6 == 3)
      cout << 0;
    else
      cout << 1;
  }
  return 0;
}
