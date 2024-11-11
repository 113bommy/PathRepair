#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  long long int t;
  cin >> t;
  while (t--) {
    long long int x;
    cin >> x;
    if (x % 2 == 0) {
      cout << (x / 2) - 1 << endl;
    } else
      cout << x / 2 << endl;
  }
  return 0;
}
