#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, t;
  cin >> n >> t;
  int x = 0;
  while (n--) {
    int z;
    cin >> z;
    t -= (86400 - z);
    ++x;
    if (t <= 0) {
      cout << x << endl;
      return 0;
    }
  }
}
