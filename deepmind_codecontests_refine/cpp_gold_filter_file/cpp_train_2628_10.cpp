#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t;
  cin >> t;
  for (int j = 1; j <= t; j++) {
    int n, m;
    cin >> n >> m;
    if (n == 1 or m == 1) {
      cout << "YES" << endl;
    } else if (n < 3 and m < 3) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
  return 0;
}
