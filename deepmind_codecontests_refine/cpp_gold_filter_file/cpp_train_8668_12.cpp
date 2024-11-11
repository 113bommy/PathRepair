#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long int t;
  cin >> t;
  while (t--) {
    long long int x{}, y{}, k{};
    cin >> x >> y >> k;
    long long int a = (y * k) + k;
    if ((a - x) % (x - 1) == 0) {
      long long int r = ((a - x) / (x - 1)) + 1;
      cout << k + r << ("\n");
    } else {
      long long int r = ((a - x) / (x - 1)) + 1;
      if (x > a)
        cout << k + r << ("\n");
      else
        cout << k + r + 1 << ("\n");
    }
  }
}
