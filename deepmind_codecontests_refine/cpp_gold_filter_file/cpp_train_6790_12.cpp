#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 1e6 + 10;
int powp[MAX_N];
int main() {
  int t;
  cin >> t;
  while (t--) {
    int a, b;
    cin >> a >> b;
    long long pow10 = 10;
    int c = 0;
    for (int i = 1; i <= 10; i++) {
      if (pow10 > b) break;
      c++;
      pow10 *= 10;
    }
    if (b == pow10 - 1) c++;
    cout << 1ll * c * a << endl;
  }
}
