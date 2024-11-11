#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long int a, b, c;
    cin >> a >> b >> c;
    cout << abs(a + b - c) + 1 << endl;
  }
  return 0;
}
