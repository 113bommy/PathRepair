#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  if (n % 2 == 0)
    cout << 3 * n / 2;
  else
    cout << 3 * (n + 1) / 2;
  return 0;
}
