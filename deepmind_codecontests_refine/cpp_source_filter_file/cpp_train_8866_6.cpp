#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int t;
  cin >> t;
  while (t--) {
    long long int n, k, x, w = 1;
    cin >> n >> k;
    if (k % 3 != 0) {
      if (n % 3 == 0) w = 0;
    } else {
      x = n % (k + 1);
      if (x % 3 == 0 && x != n) w = 0;
    }
    if (w == 0)
      cout << "Bob\n";
    else
      cout << "Alice\n";
  }
}
