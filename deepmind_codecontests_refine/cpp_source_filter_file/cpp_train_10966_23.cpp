#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  cin >> n >> k;
  if (k / n > 2)
    cout << "0\n";
  else {
    if (k % n == 0)
      cout << n;
    else
      cout << (n - 1) / 2 << endl;
  }
  return 0;
}
