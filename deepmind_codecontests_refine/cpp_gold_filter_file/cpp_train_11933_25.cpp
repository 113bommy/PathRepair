#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  if (n == 1)
    cout << "1 1\n1\n";
  else {
    cout << 2 * (n - 1);
    cout << " 2\n1 2\n";
  }
  return 0;
}
