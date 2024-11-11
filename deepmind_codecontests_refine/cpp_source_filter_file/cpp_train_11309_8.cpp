#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a, b, i, j;
  cin >> n >> a >> b;
  for (i = 0; i <= 10000000; i++) {
    if (n - a * i >= 0) {
      if ((n - a * i) % b == 0) {
        cout << "YES"
             << "\n";
        cout << i << " " << (n - a * i) / b;
        return 0;
      }
    }
  }
  cout << "NO";
}
