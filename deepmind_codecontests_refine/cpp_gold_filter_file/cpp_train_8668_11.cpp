#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    long long int x, y, k;
    cin >> x >> y >> k;
    unsigned long long int ans = ((k + y * k + x - 3) / (x - 1));
    cout << ans + k << endl;
  }
}
