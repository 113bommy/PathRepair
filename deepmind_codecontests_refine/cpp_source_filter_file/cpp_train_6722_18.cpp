#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000000007;
int main() {
  int n;
  while (cin >> n) {
    int x = ceil(sqrt(n));
    int l;
    for (int i = x; i >= 1; i--) {
      if (n % i == 0) {
        l = i;
        break;
      }
    }
    cout << l << ' ' << n / l << endl;
  }
  return 0;
}
