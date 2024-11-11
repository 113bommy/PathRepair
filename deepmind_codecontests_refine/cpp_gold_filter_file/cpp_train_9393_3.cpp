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
    long long int n;
    cin >> n;
    if (n == 1) {
      cout << -1 << endl;
      continue;
    }
    for (long long int i = 0; i < n - 1; i++) {
      cout << 3;
    }
    cout << 4 << endl;
  }
}
