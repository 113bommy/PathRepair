#include <bits/stdc++.h>
using namespace std;
long long const MOD = 1e9 + 7;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  long long n, x;
  cin >> n;
  while (n--) {
    cin >> x;
    if (x >= 14 && x % 14 <= 6 && x % 14 > 0)
      cout << "YES"
           << "\n";
    else
      cout << "NO"
           << "\n";
  }
}
