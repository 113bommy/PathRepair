#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    if (n == 2) {
      cout << 2 << endl;
      continue;
    } else if (n % 2 == 0)
      cout << 0 << endl;
    else
      cout << 1 << endl;
  }
  return 0;
}
