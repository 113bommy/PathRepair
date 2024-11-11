#include <bits/stdc++.h>
using namespace std;
double pie = 3.141592653589793238;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int t;
  t = 1;
  cin >> t;
  while (t--) {
    long long int a, b, c, n;
    cin >> a >> b >> c >> n;
    long long int sum = a + b + c + n;
    if (sum % 3)
      cout << "NO"
           << "\n";
    else {
      long long int val = sum / 3;
      if (sum - a < 0 || sum - b < 0 || sum - c < 0)
        cout << "NO"
             << "\n";
      else
        cout << "YES"
             << "\n";
    }
  }
}
