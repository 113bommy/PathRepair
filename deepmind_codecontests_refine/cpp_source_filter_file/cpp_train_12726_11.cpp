#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t > 0) {
    long int n, m;
    cin >> n >> m;
    if (n == 1) {
      cout << "0" << endl;
    } else if (n == m) {
      cout << 2 * m << endl;
    } else {
      cout << m << endl;
    }
    t--;
  }
  return 0;
}
