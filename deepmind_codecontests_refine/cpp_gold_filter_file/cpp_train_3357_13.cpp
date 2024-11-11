#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  long long t;
  cin >> t;
  while (t--) {
    int n, k, x, rem;
    cin >> n >> k;
    x = k / (n - 1);
    rem = k - x * (n - 1);
    if (!rem)
      cout << x * n - 1 << "\n";
    else
      cout << x * n + rem << "\n";
  }
}
