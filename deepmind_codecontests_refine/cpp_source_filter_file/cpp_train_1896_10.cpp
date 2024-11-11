#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int k = n % 14;
    if (k > 0 && k < 7 && n > 14)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
  return 0;
}
