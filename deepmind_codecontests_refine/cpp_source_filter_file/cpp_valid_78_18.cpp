#include <bits/stdc++.h>
using namespace std;
const long long int MOD = 1e9 + 7;
const long long int MAX_N = 1e5 + 1;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int l, r;
  long long int t;
  cin >> t;
  while (t--) {
    cin >> l >> r;
    long long int h = r / 2;
    if (l >= h)
      cout << (r % l) << "\n";
    else
      cout << (r) % (h + 1) << "\n";
  }
  return 0;
}
