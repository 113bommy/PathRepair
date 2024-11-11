#include <bits/stdc++.h>
using namespace std;
int main() {
  int T;
  cin >> T;
  while (T--) {
    int n, d;
    cin >> n >> d;
    int x, MAG = (int)sqrt(d);
    for (x = 0; x < MAG; x++) {
      if (x + (d) / (x + 1) <= n) break;
    }
    cout << (x < MAG ? "YES" : "NO") << endl;
  }
  return 0;
}
