#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n;
    m = 1;
    cout << n << endl;
    while (m <= n) {
      cout << m++ << " ";
    }
    cout << endl;
  }
  return 0;
}
