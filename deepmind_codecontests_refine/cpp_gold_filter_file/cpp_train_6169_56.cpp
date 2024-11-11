#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    if (n % 4 != 0) {
      cout << "NO"
           << "\n";
      ;
    } else {
      cout << "YES"
           << "\n";
      ;
    }
  }
  return 0;
}
