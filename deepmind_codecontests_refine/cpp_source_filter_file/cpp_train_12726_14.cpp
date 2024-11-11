#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    if (n == 0)
      cout << 1 << endl;
    else if (n == 1)
      cout << m << endl;
    else
      cout << 2 * m << endl;
  }
}
