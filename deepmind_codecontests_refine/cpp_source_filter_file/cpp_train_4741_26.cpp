#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  if (n % 3 == 0)
    cout << n / 3 * 2 << endl;
  else {
    if (n % 3 == 2) n--;
    n--;
    cout << 2 * n + 1 << endl;
  }
  return 0;
}
