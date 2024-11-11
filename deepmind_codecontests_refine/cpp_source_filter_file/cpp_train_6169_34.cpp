#include <bits/stdc++.h>
using namespace std;
int main() {
  long int t, n;
  cin >> t;
  while (t > 0) {
    cin >> n;
    if (n % 2 == 0) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
    t--;
  }
  return 0;
}
