#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    if (n < 11)
      cout << 1 << endl;
    else
      cout << ((n + 1) / 10) << endl;
  }
  return 0;
}
