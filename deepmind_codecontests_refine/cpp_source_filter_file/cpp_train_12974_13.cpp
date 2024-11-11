#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, t;
  cin >> n >> t;
  int x = 0;
  while (n--) {
    int z;
    cin >> z;
    n -= (86400 - z);
    ++x;
    if (n < 0) {
      cout << x << endl;
      return 0;
    }
  }
}
