#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  long long int a, b, n, m;
  for (int i = 0; i < t; i++) {
    cin >> a;
    cin >> b;
    cin >> n;
    cin >> m;
    if (a > b) {
      ;
      ;
    } else {
      a = a + b;
      b = a - b;
      a = a - b;
    }
    if ((a + b >= n + m) & (b >= m)) {
      cout << "YES"
           << "\n";
    } else {
      cout << "NOT"
           << "\n";
    }
  }
}
