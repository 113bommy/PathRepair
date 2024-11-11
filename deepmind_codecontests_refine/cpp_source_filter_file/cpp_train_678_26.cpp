#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n;
  cin >> n;
  if (n <= 3)
    cout << 1;
  else if (n - 1 % 2 == 0)
    cout << (n - 1) / 2;
  else
    cout << ((n - 1) / 2) + 1;
  return 0;
}
