#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    if (n == 1) {
      cout << 1 << endl;
    } else {
      long long int x = 8, sum = 0;
      for (int i = 1; i <= n / 2; i++) {
        sum += (x * i);
        x += 8;
      }
      cout << sum << endl;
    }
  }
  return 0;
}
