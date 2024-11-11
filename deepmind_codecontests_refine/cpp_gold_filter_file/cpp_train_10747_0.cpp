#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, a, b, c, d;
    cin >> n >> a >> b >> c >> d;
    int k = a - b, l = a + b;
    if ((n * k > c + d) || (n * l < c - d))
      cout << "No" << endl;
    else
      cout << "Yes" << endl;
  }
  return 0;
}
