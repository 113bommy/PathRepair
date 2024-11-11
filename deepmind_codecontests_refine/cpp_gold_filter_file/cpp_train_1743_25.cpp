#include <bits/stdc++.h>
using namespace std;
const long long tab[] = {0,   4,   10,  20,  35,  56,  83, 116,
                         155, 198, 244, 292, 341, 390, 439};
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long n;
  cin >> n;
  if (n <= 14)
    cout << tab[n];
  else
    cout << (n - 14) * 49 + tab[14];
  return 0;
}
