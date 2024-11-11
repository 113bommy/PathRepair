#include <bits/stdc++.h>
using namespace std;
int main() {
  long t;
  cin >> t;
  while (t--) {
    long n;
    cin >> n;
    if (n / 10 == 9) {
      cout << n / 10 + 1 << endl;
    } else
      cout << n / 10 << endl;
  }
  return 0;
}
